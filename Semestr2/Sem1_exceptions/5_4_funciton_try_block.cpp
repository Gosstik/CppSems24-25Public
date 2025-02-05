#include <format>
#include <iostream>
#include <stdexcept>

// function try block
// https://en.cppreference.com/w/cpp/language/try

void Handler(int x) noexcept try {
  if (x > 0) {
    throw std::logic_error("x must be <= 0");
  }
  std::cout << "X = " << x << '\n';
} catch (const std::exception& err) {
  std::cout << std::format(
      "caught in Handler try block for x={} :{}\n", x, err.what()
  );
}

int main() {
  try {
    Handler(1);
  } catch (...) {
    std::cout << "caught!\n";
  }
}
