#include <iostream>

struct Base {
  void Foo() {  // NOLINT
    std::cout << 1 << '\n';
  }
};

struct Derived : Base {
  void Foo() {  // NOLINT
    std::cout << 2 << '\n';
  }

 private:
  using Base::Foo; // OK
};

int main() {
  Derived d{};
  d.Base::Foo();
  // d.Foo(); //* OK
}
