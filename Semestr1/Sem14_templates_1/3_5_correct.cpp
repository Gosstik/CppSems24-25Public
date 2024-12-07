#include <iostream>

template <typename T>
void Foo(T& x) {
  std::cout << 1;
}

template <typename T>
void Foo(T x) {
  std::cout << 2;
}

////////////////////////////////////////////////////////////////////////////////

template <typename T>
void Bar(const T& x) {
  std::cout << 1;
}

template <typename T>
void Bar(T& x) {
  std::cout << 2;
}

////////////////////////////////////////////////////////////////////////////////

int main() {
  int x = 0;
  int& y = x;

  Foo(x); // CE
  Foo(1); // OK

  Bar(x); // OK
}
