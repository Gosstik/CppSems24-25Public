#include <iostream>
#include <new>

// It is UB. Use std::launder:
// https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2017/p0532r0.pdf

// standard: [basic.life], 8.5 example (p. 65 in C++23)
// https://isocpp.org/files/papers/N4860.pdf

// until c++17 std::vector<Type>, where Type contains const or ref fields is UB
// Example: push_back, pop_back, push_back (in open-std cite)

// TODO: problem in variant when we store variant<Base, Derived>

struct A {
  virtual int Foo();
  virtual ~A() = default;
};

struct B : A {
  int Foo() override {
    new (this) A;
    return 1;
  }
};

int A::Foo() {
  new (this) B;
  return 2;
}

int Bar1() {
  A a;
  int n = a.Foo();
  int m = a.Foo();
  return n + m;
}

int Bar2() {
  A* a = new A;
  int n = a->Foo();
  int m = a->Foo();
  delete a;
  return n + m;
}

int Bar3() {
  A a;
  int n = a.Foo();
  int m = std::launder(&a)->Foo();
  return n + m;
}

int main() {
  std::cout << Bar1() << '\n';  // 4, UB
  std::cout << Bar2() << '\n';  // 3, UB
  std::cout << Bar3() << '\n';  // 3, OK
}
