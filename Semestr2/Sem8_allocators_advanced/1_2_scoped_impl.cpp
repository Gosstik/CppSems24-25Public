#include <iostream>
#include <vector>
#include <string>
#include <scoped_allocator>
#include <memory> // uses_allocator

////////////////////////////////////////////////////

// Live coding

template <typename Alloc>
struct scoped_allocator_adaptor {
  Alloc alloc;

  template <typename T, typename... Args>
  void construct(T* ptr, const Args&... args) {
    if constexpr (std::uses_allocator_v<T, Alloc>) { // https://en.cppreference.com/w/cpp/memory/uses_allocator
      using InnerAlloc = typename T::allocator_type;
      // 
      alloc.construct(ptr, args..., InnerAlloc(alloc));
    } else {
      alloc.construct(ptr, args...);
    }
  }
};


////////////////////////////////////////////////////


template <typename T>
using MyAlloc = std::allocator<T>;

int main() {
  using MyString = std::basic_string<char, std::char_traits<char>, MyAlloc<char>>;

  MyAlloc<MyString> alloc;

  std::vector<MyString, MyAlloc<MyString>> v(alloc);
//  std::vector<MyString, std::scoped_allocator_adaptor<MyAlloc<MyString>>> v(alloc);


  v.push_back("abc");
  v.push_back("ced");
}