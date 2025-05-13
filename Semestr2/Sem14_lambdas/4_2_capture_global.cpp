#include <iostream>

// Only local variables must be captured

// TODO


int global = 0;

struct S {
  void Foo() {
    int local = 1;
    static int st = 3;
    auto f = [local, cl_local = cl]() { return global + local + cl_local + cl_st + st; }; // OK
    std::cout << f() << std::endl;
  }

  int cl;
  int lc2;
  inline static int cl_st = 3;
};

int main() {
  int local = 1;
  auto f = [local]() { return global + local; };
  std::cout << f() << std::endl;
}
