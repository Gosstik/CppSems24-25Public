#include <iostream>

// Base --- Abstract Class (has at least 1 pure virtual function)
// !!! All pure virtual functions must be defined in successors
// !!! otherwise derived class is abstract

struct Base {  // NOLINT
  virtual void Foo() = 0;
};

void Base::Foo() {
  std::cout << "Base::Foo()\n";
}

struct Derived : Base {
  void Foo() override {
    std::cout << "Derived::Foo()\n";
  }
};

int main() {
  // Base b;  // CE
  Derived d;
  Base& rb = d;  // OK

  rb.Foo();
  rb.Base::Foo(); // OK, devirtualization
}
