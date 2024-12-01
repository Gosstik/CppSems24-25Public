#include <iostream>

// Singleton

struct S {
  void Bar() { // NOLINT
    ++value;
  }

  static void Foo() {
    // Bar(); // CE
    ++value;
    std::cout << "static Foo\n";
  }

  static int value; // declaration
  // static int value = 1; // CE
  static const int const_value = 2; // OK // NOLINT
  inline static int inline_value = 3; // declaration and definition
};

int S::value = 1; // definition

int main() {
  S::Foo(); // no object required

  S s;
  s.Foo(); // also possible, same as S::Foo(), not recommended to be used

  std::cout << S::value << '\n';
  std::cout << S::inline_value << '\n';
}
