#include <iostream>
#include <vector>

// CTAD --- Class Template Argument Deduction (since c++17)

int main() {
  std::vector v = {1, 2, 3}; // OK
  // Helpful with std::pair and std::tuple

  std::vector v2{v.begin(), v.end()}; // vector of iters (initializer list)

  std::vector v3(v.begin(), v.end()); // vector of ints (deduction guide)
}
