#include <iomanip>
#include <iostream>

// dynamic_cast works only for polymorphic types

struct Base {
  void Foo() const {
    std::cout << x << '\n';
  }

  int x = 0;
};

struct Derived : Base {
  void Foo() const {
    std::cout << y << '\n';
  }

  int y = 1;
};

int main() {
  std::cout << std::boolalpha;

  Derived d;
  Base& b = d;
  auto dd = dynamic_cast<Derived&>(b);  // CE
  auto sd = static_cast<Derived&>(b);   // OK

  dd.Foo();
  sd.Foo();
}
