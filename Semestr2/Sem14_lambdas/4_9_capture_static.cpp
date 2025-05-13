#include <iostream>

// static variables are accessible by default and are not captured

int main() {
  static int x = 0;
  auto f = [=]() mutable {
    ++x;
  };
  f();
  std::cout << x << '\n'; // 1
}
