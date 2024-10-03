#include <iostream>
#include <vector>

int main() {
  std::vector vec = {1, 2, 3}; // no template argument
  for (size_t i = 0; i < vec.size(); ++i) {
    std::cout << vec[i] << std::endl;
  }
}
