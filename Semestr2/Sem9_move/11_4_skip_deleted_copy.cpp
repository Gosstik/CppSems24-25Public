#include <iostream>

struct S {
  int a = 0;
  S() = default;
  S(const S&) = delete;
};

S Foo() {
  return {};
}

int main() {
  S s = Foo();
  std::cout << s.a << '\n';
}
