#include <iostream>

struct Base {
  int x;
};

struct Derived: Base {
  double y;
};

int main() {
  std::cout << sizeof(Derived) << '\n'; // ???
}
