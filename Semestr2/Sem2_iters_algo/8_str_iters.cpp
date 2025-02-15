#include <iostream>
#include <vector>

int main() {
  std::vector<char> vec = {",", ";"};
  for (auto elem : vec) {
    std::cout << elem << '\n';
  }
}
