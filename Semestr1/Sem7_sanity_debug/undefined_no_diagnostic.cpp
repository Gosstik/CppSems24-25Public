#include <iostream>
#include <cstdint>
#include <limits>

// clang++ -fsanitize=undefined undefined_no_diagnostic.cpp

int main() {
  int64_t i64 = std::numeric_limits<int64_t>::max();
  int32_t i32 = i64; // implementation defined behaviour, not UB
  std::cout << i32 << '\n';
}
