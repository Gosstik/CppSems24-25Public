#include <iostream>

struct Base {
  int x = 1;
  void Foo() const {
    std::cout << x << '\n';
  }
};

struct Derived: Base {
  int x = 2;
  void Foo() const {
    std::cout << x + Base::x << '\n';
  }
};

int main() {
  Derived d{};

  d.Foo();
  std::cout << d.x << '\n';

  d.Base::Foo();
  std::cout << d.Base::x << '\n';
}
