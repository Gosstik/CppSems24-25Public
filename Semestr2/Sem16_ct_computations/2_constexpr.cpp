// constexpr => const
// const !> constexpr

// constexpr variables can be init only by "constant expressions"

// constexpr function --- call to that function is "constant expressions"

// since C++14 --- control statements, vars declaration, arrays, pointers

// Most of UB cases are CE in compile time !!!
// e.g. dereference of invalid pointer is CE

constexpr int Max(int x, int y) {
  return x < y ? y : x;
}

constexpr int Foo(int x) {
  x = x++ + ++x;
  return x;
}

int main() {
  constexpr int x = 5;

  static_assert(Foo(1) == 4); // Not a CE
}
