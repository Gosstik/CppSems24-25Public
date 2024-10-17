#include <cstdint>
#include <iostream>
#include <limits>

// Compile program with the following flags to see warnings
// g++ -Wall -Wextra -Wpedantic warnings.cpp

// More flags are in README.md

int main() {
  {
    int a = 0;  // warning: unused variable ‘a’ [-Wunused-variable]
    int b = 1;
    std::cout << b;
  }

  {
    int x = 0;
    int y = 1;
    x + y;  // warning: statement has no effect [-Wunused-value]
  }

  {
    int x = 0;
    if (x = 1) {  // warning: suggest parentheses around assignment used as
                  // truth value [-Wparentheses]
      std::cout << "x is 1\n";
    }
  }

  // -pedantic or -Wpedantic
  {
    int a[] = {};  // error: zero-size array ‘a’
    int b[0];  // warning: ISO C++ forbids zero-size array ‘b’ [-Wpedantic]
  }

  {
    // -Woverflow (overflow in conversion from)
    int32_t y = std::numeric_limits<uint64_t>::max();
    std::cout << y << '\n';
  }

  {
    // No warnings are emitted even with flags :(
    uint64_t x = std::numeric_limits<uint64_t>::max();
    int32_t y = x;
    std::cout << y << '\n';
  }
}
