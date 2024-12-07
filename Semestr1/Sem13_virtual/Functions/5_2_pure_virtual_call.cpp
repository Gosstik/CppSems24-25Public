#include <iostream>

struct Base {  // NOLINT
  virtual void Foo() = 0;

  void Foo() {  // NOLINT
    std::cout << "f\n";
    // VirtualFunc(); //* RE, no compiler warning
    // Base::VirtualFunc(); //* OK if has definition
  }

  Base() {
    std::cout << "Base\n";
    // VirtualFunc();  //* RE, has compiler warning
    Foo();
  }

  virtual ~Base() = default;
};

void Base::Foo() {
  std::cout << "Base::VirtualFunc()\n";
}

struct Derived : Base {
  void Foo() override { std::cout << "Derived::VirtualFunc()\n"; }

  Derived() { std::cout << "Derived()\n"; };
};

int main() {
  // Derived d;
  Base& b = *new Derived();
  b.Foo();
}
