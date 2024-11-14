#include <iostream>

struct S {
  void Bar() {
    ++value;
  }

  static void Foo() {
    // Bar(); // CE
    ++value;
    std::cout << "static Foo\n";
  }

  static int value;
};

int main() {
  S::Foo(); // no object required

  S s;
  s.Foo(); // also possible, same as S::Foo()
}
