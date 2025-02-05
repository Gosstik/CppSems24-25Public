#include <iostream>

// Why exceptions cannot be placed on stack?

// Memory for exception is allocated on heap, but not with new/malloc.
// Is uses __cxa_allocate_exception:
// https://github.com/llvm-mirror/libcxxabi/blob/ce3db128f9e4d6d19d1cdbe39bb45fcc64a5adb0/src/cxa_exception.cpp#L183

// __aligned_malloc_with_fallback
// https://github.com/llvm-mirror/libcxxabi/blob/ce3db128f9e4d6d19d1cdbe39bb45fcc64a5adb0/src/fallback_malloc.cpp#L212

// Path:
// /usr/include/c++/13/bits/cxxabi_init_exception.h : line 63

// see godbolt

struct A {
  A() {
    std::cout << "A\n";
  }
  A(const A&) {
    std::cout << "A(copy)\n";
  }
  ~A() {
    std::cout << "~A\n";
  }
};

int main() {
  try {
    throw A();
  } catch (const A& a) {
    std::cout << "caught! &a=" << &a << '\n';
  }
}
