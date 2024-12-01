#include <iostream>

// Out?

struct A {
  A(int x) { std::cout << "A" << x; } // NOLINT
  ~A() { std::cout << "~A"; }
};

struct Base {
  Base(int x) : a0(x) { std::cout << "Base"; } // NOLINT
  ~Base() { std::cout << "~Base"; }

  A a0;
};

struct Derived : Base {
  Derived(int y) : Base(0), a1(y) { std::cout << "Derived"; } // NOLINT
  ~Derived() { std::cout << "~Derived"; }

  A a1;
};

int main() {
  Derived d = 1;
  std::cout << '\n';
}
