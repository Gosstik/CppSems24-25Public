#include <iostream>

template <typename T>
void Foo(T) {
  std::cout << "T";
}

struct S {};

template <typename T>
void CallFoo(T t, S s) {
  Foo(t);  // dependent, "S"
  Foo(s);  // independent, "T"
}

void Foo(S s) {
  std::cout << "S";
}

int main() {
  S s;
  CallFoo(s, s);
}
