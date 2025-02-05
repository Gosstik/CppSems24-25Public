#include <iostream>

struct A {
  A() {
    std::cout << "A\n";
    throw std::logic_error("you shall not pass!!!\n");
  }
};

A global;

void Foo() {
  std::cout << "Foo\n";
  static A local;
}

int main() {
  std::cout << "Main\n";
  // Foo();
}
