#include <iostream>
#include <vector>
#include <string>
#include <scoped_allocator>


template <typename T>
using MyAlloc = std::allocator<T>;

int main() {
  using MyString = std::basic_string<char, std::char_traits<char>, MyAlloc<char>>;

  MyAlloc<MyString> alloc;

  // std::vector<MyString, MyAlloc<MyString>> v(alloc);
 std::vector<MyString, std::scoped_allocator_adaptor<MyAlloc<MyString>>> v(alloc);

  v.push_back("abc");
  v.push_back("ced");
}
