#include <iostream>
#include <cstdint>

void Foo(int) {}
void Foo(double) {}
void Foo(bool);

void Foo(int64_t) {}

int main() {
  std::cout << (void*)Foo << '\n'; // ???
  void (*fooi)(int) = Foo; // ???
  void (*foob)(bool) = Foo; // ???
}
