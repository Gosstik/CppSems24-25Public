#include <iostream>

// https://cppinsights.io/

template <typename T>
T Min(T a, T b) {
  return a < b ? a : b;
}

template <typename T>
T Max(T& a, T& b) {
  return a < b ? a : b;
}

int main() {
  {
    // cut cv

    const int& a = 1;
    const int& b = 2;
    std::cout << Min(a, b) << std::endl;  // min<int>(int a, int b);
  }

  {
    const int& a = 1;
    const int& b = 2;
    std::cout << Max(a, b) << std::endl; // min<const int>(const int& a, const int& b);
  }
}
