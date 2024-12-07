#include <iostream>

template <typename T>
void Foo(T x) {
  std::cout << x << '\n';
}

void Foo(int) {
  std::cout << 1 << '\n';
}

int main() {
  unsigned int x = 0;
  Foo(x);
}
