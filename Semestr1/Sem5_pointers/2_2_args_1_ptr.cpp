#include <iostream>

void Foo(int* a) {  // 1
  std::cout << 1;
  std::cout << sizeof(a) << '\n';
}

void Foo(int a[3]) {  // 2
  std::cout << 2;
  std::cout << sizeof(a) << '\n';
}

void Foo(int a[]) {  // 3
  std::cout << 2;
  std::cout << sizeof(a) << '\n';
}

int main() {
  // 1 == 2 == 3 --- all are pointers to int
  // Rule: when function accepts array, array to pointer conversion occurs
}
