#include <iostream>
#include <cstdint>
#include <limits>

int main() {
  int64_t i64 = std::numeric_limits<int64_t>::max();
  ++i64; // signed integer overflow
  std::cout << i64 << '\n';
}
