#include <iostream>

struct Base {
  int x = 1;
  void Foo() const { std::cout << x << '\n'; }
};

struct Derived : Base {
  int y = 2;
  void Foo() const { std::cout << y << '\n'; }
};

int main() {
  Derived d{};
  d.Foo();  // ???

  Base b(d);
  b.Foo();  // ???

  Base& rb(d);
  rb.Foo();  // ???

  Derived rd(b);
  rd.Foo();  // ???
}
