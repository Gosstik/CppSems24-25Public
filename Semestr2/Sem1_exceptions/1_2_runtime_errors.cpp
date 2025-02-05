#include <iostream>
#include <vector>

// Segmentation fault, floating point exception - not exceptions of C++.
// Such exceptions are generated by processors or OS.

int main() {
  std::vector<int> v;

  try {
    // v[1'000'000] = 1;
    v.at(1'000'000) = 1;
  } catch (...) {
    std::cout << "caught!!!\n";
  }

  std::cout << "Ending main\n";
}
