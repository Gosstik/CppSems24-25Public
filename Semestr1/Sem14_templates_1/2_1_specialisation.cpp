#include <iostream>

// Example of specialization in stl ??? --- vector<bool>

template <typename T>
void Print(T val) {
  std::cout << val << '\n';
}

template <>
void Print<int>(int val) {
  std::cout << "int version\n";
  std::cout << val << '\n';
}

int main() {
  Print(1);
  Print(1.0);
}
