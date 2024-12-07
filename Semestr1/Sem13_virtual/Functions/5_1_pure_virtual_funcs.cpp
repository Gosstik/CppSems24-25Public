#include <iostream>

// Base --- Abstract Class (has at least 1 pure virtual function)
// !!! All pure virtual functions must be defined in successors
// !!! otherwise derived class is abstract

struct Base {  // NOLINT
  virtual void VirtualFunc() = 0;
};

struct Derived : Base {
  void VirtualFunc() override { std::cout << "VirtualFunc()\n"; }
};

int main() {
  // Base b;  // CE
  Derived d;
  Base& rb = d;  // OK
}
