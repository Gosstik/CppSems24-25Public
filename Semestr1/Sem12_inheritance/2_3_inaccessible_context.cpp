#include <iostream>

struct Granny {
  int x;
  void Foo() {}
};

struct Mom : private Granny {
  friend int main();
  int x;
};

struct Son : Mom {
  int x;
  void Foo(Granny& g) {  // CE: Granny is inaccessible in this context
    std::cout << g.x << '\n';
  }

  void Bar(::Granny& g) {  // OK
    std::cout << g.x << '\n';
  }
};

int main() {
  Son s{};
  std::cout << s.Granny::x;  // OK, main is Mom friend
  std::cout << s.Mom::Granny::x;  // OK, also correct
}
