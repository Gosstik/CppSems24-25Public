#include <cstdint>
#include <iostream>
#include <stdexcept>

// Try to comment if

int64_t Div(int64_t a, int64_t b) {
  if (b == 0) {
    throw std::logic_error("Divide by zero!");
  }
  return a / b;
}

int main() {
  int a = 1;
  int b = 0;

  try {
    Div(a, b);
  } catch (std::logic_error& err) {
    std::cout << err.what() << '\n';
  }

  std::cout << a / b << '\n';
}
