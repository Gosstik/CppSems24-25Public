

// No overloading by constexpr because it is not a part of func signature.
// Object with constexpr ctor can be a template parameter.
// Only const constexpr methods are allowed to use with template args. 

struct S {
  constexpr S(int x): x(x) {} // constexpr ctor
  int x;
};

constexpr int Foo(int x) {
  S s(x);
  return s.x;
}

int main() {
  static_assert(Foo(5) == 5);
}
