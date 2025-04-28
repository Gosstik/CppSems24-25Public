#include <cstddef>
#include <memory>
#include <utility>
#include <type_traits>

//// Discuss
// size_t count
// static size_t count
// size_t* count

// Save bool in last bit of count_ whether we were created from ControlBlock or
// from ptr

// TODO: how to use Deleter and Allocator simultaneously (see ctors)
// If object was created from make_shared, Deleter is not required (only Alloc)

// TODO: allocate_shared
// TODO: delete this

template <typename T>
class SharedPtr {
 private:
  struct ControlBlockBase {
    size_t shared_count;
    size_t weak_count;
  };

  template <typename Deleter, typename Alloc>
  struct ControlBlockRegular {
    Deleter deleter;
    Alloc alloc;
  };

  template <typename Alloc>
  struct ControlBlockMakeShared : ControlBlockBase {
    T value;
    Alloc alloc;
  };

  // TODO: do we need U ???
  template <typename U, typename... Args>
  friend SharedPtr<U> MakeShared(Args&&...);

  SharedPtr(ControlBlockMakeShared* block) {}  // TODO
 public:
  SharedPtr(T* ptr) : ptr_(ptr), count_(new size_t(1)) {
    if constexpr (std::is_base_of_v<std::enable_shared_from_this<T>, T>) {
      ptr->sptr = *this;
    }
  }

  SharedPtr(const SharedPtr& other) : ptr_(other.ptr_), count_(other.count_) {
    ++*count_;
  }

  ~SharedPtr() {
    if (count_ == 0) {  // TODO: do we need it ???
      return;
    }
    --*count_;
    if (*count_ == 0) {
      // delete count_; // WRONG now
      delete ptr_;
    }
  }

 private:
  T* ptr_;
  ControlBlockBase* block_;
};

////////////////////////////////////////////////////////////////////////////////

// MakeShared (since c++11)

// To avoid double call to operator new

template <typename T, typename... Args>
SharedPtr<T> MakeShared(Args&&... args) {
  auto* p = new SharedPtr<T>::ControlBlockMakeShared{T(std::forward<Args>(args)...), 1};
  return SharedPtr<T>(p);
}

////////////////////////////////////////////////////////////////////////////////

// allocate_shared

template <typename T, typename Alloc, typename... Args>
SharedPtr<T> AllocateShared(const Alloc& alloc, Args&&... args) {
  using BlockAlloc = typename std::allocator_traits<Alloc>::template rebind_alloc<SharedPtr<T>::ControlBlockMakeShared<T, Alloc>>;
  BlockAlloc ba = alloc;
  auto* ptr = ba.allocate(1); // TODO: sizeof instead 1
  ba.construct(ptr, 1, 0, std::forward<Args>(args)..., alloc);
  // return ...;
}

////////////////////////////////////////////////////////////////////////////////

int main() {}
