#include <iostream>
#include <stdexcept>

// https://stackoverflow.com/questions/43609186/local-static-object-and-exception

struct A {
  A() {
    std::cout << "A()" << std::endl;
    throw std::runtime_error("Ooops");
  }
};

void Foo() {
  static A a = A();
  std::cout << "Continue" << std::endl;
}

int main() {
  try {
    Foo();
  } catch (const std::exception& e) {
    std::cout << "Caught: " << e.what() << std::endl;
  }

  try {
    Foo();
  } catch(const std::exception& e) {
    std::cout << "Caught: " << e.what() << std::endl;
  }
}
