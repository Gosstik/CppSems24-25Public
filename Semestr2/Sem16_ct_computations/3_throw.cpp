#include <iostream>

// throw cannot be caught in compile time

constexpr int Foo(int x) {
  if (x > 100) {
    throw 1;
  }
  return x;
}

int main() {
  static_assert(Foo(1) == 1);      // OK
  // static_assert(Foo(101) == 101);  // CE
}
