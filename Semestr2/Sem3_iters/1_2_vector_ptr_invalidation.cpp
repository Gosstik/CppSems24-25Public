#include <deque>
#include <iostream>
#include <vector>

int main() {
  // std::vector<int> cont(10, 1);
  std::deque<int> cont(10, 1);  // No UB
  int* p = &cont[5];
  int& r = cont[5];  // UB

  cont.push_back(1);        // pointer invalidation
  std::cout << *p << '\n';  // UB
}
