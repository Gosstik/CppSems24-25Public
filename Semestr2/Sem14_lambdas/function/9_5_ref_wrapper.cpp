#include <functional>
#include <iostream>

// std::reference_wrapper
// std::ref, std::cref

int Sum(int x, int y) {
  return x + y;
}

int main() {
  int x = 5;
  auto f = std::bind(Sum, std::placeholders::_1, std::ref(x));
  std::cout << f(5) << '\n'; // 10
  ++x;
  std::cout << f(5) << '\n'; // 11
}
