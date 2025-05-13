#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

template <typename T>
void Debug() = delete;

bool Foo(int a, int b) {
  return a > b;
}

template <typename Lambda>
void Wrapper(Lambda l) {
  l(1, 1);
}

int main() {
  std::vector<int> vec = {5, -1, 4, -2, -3};

  auto cmp = [](int a, int b) { // functional object
    return a * a < b * b;
  };

  Wrapper(cmp);

  bool (*cmp2)(int, int) = [](int a, int b) { // functional object
    return a * a < b * b;
  };

  bool (*foo)(int, int) = Foo;

  std::sort(vec.begin(), vec.end(), [](int a, int b) {
    return a * a < b * b;
  });
  std::sort(vec.begin(), vec.end(), cmp);

  //// candidate function [with T = (lambda at 1_usage.cpp:11:14)] has been
  //// explicitly delete
  // Debug<decltype(cmp)>();

  for (auto val : vec) {
    std::cout << val << " ";
  }
  std::cout << '\n';

  std::cout << typeid(cmp).name() << '\n';
}
