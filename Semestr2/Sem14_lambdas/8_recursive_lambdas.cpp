#include <iostream>

int main() {
  // CE
  // auto fib1 = [](int n) {
  //   return (n > 2) ? fib1(n - 1) + fib1(n - 2) : 1;
  // };

  // // CE
  // auto fib2 = [](int n) {
  //   return (n > 2) ? (*this)(n - 1) + (*this)(n - 2) : 1;
  // };

  // // CE: unknown return type (without call compiles ???)
  // auto fib3 = [](this auto& self, int n) {
  //   return (n > 2) ? self(n - 1) + self(n - 2) : 1;
  // };

  // OK
  auto fib = [](this auto& self, int n) -> int {
    return (n > 2) ? self(n - 1) + self(n - 2) : 1;
  };

  std::cout << fib(5) << '\n'; // 5
}
