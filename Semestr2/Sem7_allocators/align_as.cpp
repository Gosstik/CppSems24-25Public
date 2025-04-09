#include <iostream>

template <typename T>
struct S {
  int x;
  char c;
  double d;
  alignas(T) char s[10];

  void Foo() {}
};

int main() {
  // std::cout << alignof(S) << '\n';
  // char* t = new char(80);
  // S* s = reinterpret_cast<S*>(t);

  // std::cout << 
}
