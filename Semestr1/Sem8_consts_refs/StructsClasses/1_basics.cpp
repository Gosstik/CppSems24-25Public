#include <iostream>

class C {};

struct S {
  int x = 0;
  int y = 1;
  int z = 2;
};

struct Outer {
  struct Inner {
    int b;
  };

  int a;
};

int main() {
  {
    std::cout << sizeof(Outer) << '\n'; // ???
  }

  {
    // from C
    S s = {
      .y = 4,
      .z = 5,
    };

    std::cout << s.x << s.y << s.z << '\n';
  }
}
