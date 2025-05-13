#include <iostream>
#include <type_traits>

template <auto Lambda = [] {}>
struct S {
  S() {
    Lambda();
  }

  using FuncType = decltype(Lambda);
};

int main() {
  S s1;
  S s2;
  static_assert(std::is_same_v<decltype(s1), decltype(s2)>); // CE
}
