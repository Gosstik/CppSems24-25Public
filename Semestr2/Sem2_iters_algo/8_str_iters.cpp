#include <iostream>
#include <vector>

int main() {
  std::vector<int> v1{1, 2, 3};
  std::vector<int> v2(v1.begin(), v1.end());

  const char* c1 = ";";
  const char* c2 = ",";
  std::vector<char> vec(c2, c1);
  // std::vector<char> vec(c2, c1);
  for (auto elem : vec) {
    std::cout << elem << '\n';
  }
}
