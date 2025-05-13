
// constexpr may be omitted in override function, but if it is called in
// compile time - it is CE

// dynamic_cast works.

// since c++17: creation of lambda

struct Base {
  int x = 0;
  constexpr virtual int Foo() {
    return x;
  }
};

struct Derived: Base {
  constexpr int Foo() override {
    return x + 1;
  }
};

constexpr int Bar(int x) {
  Derived d;
  Base b;
  Base& bd = d;

  return (x % 2 == 0 ? bd : b).Foo();
}

int main() {
  static_assert(Bar(0) == 1);
  static_assert(Bar(1) == 0);
}
