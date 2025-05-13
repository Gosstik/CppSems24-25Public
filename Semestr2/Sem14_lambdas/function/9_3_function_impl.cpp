#include <iostream>
#include <type_traits>
#include <memory>

// std::invoke: https://en.cppreference.com/w/cpp/utility/functional/invoke
// INVOKE: https://en.cppreference.com/w/cpp/utility/functional

// TODO: why not to use soo in shared_ptr?
// TODO: use union

// We want function to be on stack, so we can't use virtual calls.
// In shared_ptr we will allocate memory for counter so it uses virtual calls.
// So we will use small object optimization.

// No support for custom allocator since c++17.
// https://en.cppreference.com/w/cpp/utility/functional/function/function
// https://en.cppreference.com/w/cpp/utility/functional/function/function#Notes

// ! One argument
template <typename T>
class function;

template <typename Ret, typename... Args>
class function<Ret(Args...)> {
 private:
  struct Base {
    virtual Ret call(Args...) = 0;
    virtual ~Base() = default;
  };

  template <typename F>
  struct Derived : Base {
    F f;
    Derived(const F& f) : f(f) {}
    Derived(F&& f) : f(std::move(f)) {}
    ~Derived() override = default;

    // use std::invoke (since c++17)
    Ret call(Args... args) override {
      if constexpr (!std::is_member_function_pointer_v<F>) {
        // cast first arg and call func
        std::abort(); // TODO: call with correct syntax
      } else if constexpr (std::is_member_object_pointer_v<F>) {
        std::abort(); // TODO: call with correct syntax
      } else {
        return f(std::forward<Args>(args)...);
      }
    }
  };

  static const size_t BUFFER_SIZE = 16;
  // Small object optimization
//  Base* fptr;
  void* fptr;
  alignas(std::max_align_t) char buffer[BUFFER_SIZE];

  // get rid of virtual functions
  using invoke_ptr_t = Ret(*)(void*, Args...);
  using destroy_ptr_t = void(*)(void*);
  invoke_ptr_t invoke_ptr;
  destroy_ptr_t destroy_ptr;

  template <typename F>
  static Ret invoker(F* fptr, Args... args) {
    return (*fptr)(std::forward<Args>(args)...);
  }

  template <typename F>
  static void destroyer(F* fptr) {
    if constexpr (sizeof(F) > BUFFER_SIZE) {
      delete fptr;
    } else {
      fptr->~F();
    }
  }

 public:
//  function(auto&& func)
//      : fptr(new Derived<std::remove_reference_t<decltype(func)>>(func)) {} // TODO: what if decltype(func) == const T&

  template <typename F>
  function(const F& func)
      : invoke_ptr(reinterpret_cast<invoke_ptr_t>(&invoker<F>)),
        destroy_ptr(reinterpret_cast<destroy_ptr_t>(&destroyer<F>)) {
    if constexpr (sizeof(F) > BUFFER_SIZE) {
      fptr = new F(func);
    } else {
      new (buffer) F(func);
      fptr = buffer;
    }
  }

  ~function() {
//    delete fptr;
    destroy_ptr(fptr);
  }

// no && !!!
  Ret operator()(Args... args) const {
//    return fptr->call(std::forward<Args>(args)...);
    return invoke_ptr(fptr, std::forward<Args>(args)...);
  }
};

// TODO: std::function for NotCopyable
// see std::move_only_function
// TODO: std::copyable_function (Anton Polukhin)
struct NotCopyable {
  std::unique_ptr<int> p{new int(5)};
  int operator()(int x) {
    return x + *p;
  }
};
