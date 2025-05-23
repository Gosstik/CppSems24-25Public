#include <iostream>
#include <set>

// Before c++20 lambda did not have default ctor

// Closure --- type of lambda, generated by compiler

auto GetCmp() {
  return [](int a, int b) {
    return a < b;
  };
}

int main() {
  auto cmp = [](int a, int b) {
    return a < b;
  };
  // TODO: why CE
  std::set<int> s0(cmp);                 // CE
  std::set<int, decltype(cmp)> s1(cmp);  // OK
  std::set<int, decltype(cmp)> sd;       // OK since c++20

  // clang-format off
  std::set<int, decltype(cmp)> s2([](int a, int b) { // CE
    return a < b;
  });
  std::set<int, decltype([](int a, int b) { return a < b; })> s3([](int a, int b) { // CE
    return a < b;
  });
  // clang-format on

  // !!!
  auto cmp2 = GetCmp();
  std::set<int, decltype(cmp2)> gs(GetCmp());  // OK
}
