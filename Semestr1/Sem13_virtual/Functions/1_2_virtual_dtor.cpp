#include <iostream>

// ??? Definition of virtual function, polymorphic type.

struct Base {
  int* b = new int(0);

  Base() {
    std::cout << "Base()\n";
  }

  // virtual ~Base() {
  //   std::cout << "~Base()\n";
  //   delete b;
  // }

  ~Base() = default; // IS NOT VIRTUAL BY DEFAULT, even if ~Derived() is virtual !!!
};

struct Derived: Base {
  int* d = new int(0);

  Derived() {
    std::cout << "Derived()\n";
  }

  virtual ~Derived() {
    std::cout << "~Derived()\n";
    delete d;
  }

  // ~Derived() {
  //   std::cout << "~Derived()\n";
  //   delete d;
  // }
};

int main() {
  Derived* pd = new Derived(); // NOLINT
  Base* pb = pd;
  delete pb; // out ???
}
