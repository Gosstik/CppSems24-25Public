#include <iostream>

// strict aliasing
// std::launder ...

int Foo(float *f, int *i) {
  *i = 1;
  *f = 0;

  return *i;
}

int main() {
  int x = 0;

  std::cout << x << "\n";  // Expect 0
  x = Foo(reinterpret_cast<float *>(&x), &x);
  std::cout << x << "\n";  // Expect 0 ?
}
