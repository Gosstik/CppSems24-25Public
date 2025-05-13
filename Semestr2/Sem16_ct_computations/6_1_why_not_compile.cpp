#include <iostream>
#include <type_traits>

struct S {};

int main() {
  // Is it possible that static_assert below gives CE for some structure S?
  S s1;
  S s2;
  static_assert(std::is_same_v<decltype(s1), decltype(s2)>); // CE here
}
