#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

int main() {
  int a = 0;
  int b = 1;

  // it is constant method
  auto const_version = [a, &b]() {
    // ++a;  // CE
    ++b;  // OK
  };

  auto mutable_version = [a, &b]() mutable {
    ++a;  // CE
    ++b;  // OK
  };

  //////////////////////////////////////////////////////////////////////////////

  int r = 1;
  auto cmp = [r](int x, int y) mutable {
    return x * r < y * r;
  };
  std::set<int, decltype(cmp)> s(cmp); // cmp must be invocable as const
  s.insert(1);  // CE
}
