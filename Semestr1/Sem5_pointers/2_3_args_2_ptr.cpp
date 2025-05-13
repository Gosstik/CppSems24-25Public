#include <iostream>

void Bar(int**) {  // 1
  std::cout << 1 << '\n';
}

void Bar(int (*)[3]) {  // 2
  std::cout << 2 << '\n';
}

void Bar(int[3][3]) {  // 3
  std::cout << 3 << '\n';
}

void Bar(int[][3]) {  // 4
  std::cout << 4 << '\n';
}

void Bar(int[3][]) {  // 5
  std::cout << 5 << '\n';
}

int main() {
  // 2 == 3 == 4
  // 5 - CE

  int a[3][3]{};
  Bar(a);  // 1 or 2 ???

  int* b1[3] = a; // CE
  int(*b2)[3] = a; // OK
  Bar(b2);

  int** c1 = a; // CE
  int** c1 = b2; // CE
  // 2 dim arrays actually do 1 dereference and have special structure
  // Therefore no casts are permitted

  int x[3];
  Bar(&x); // 2
  int* px = x; // array to pinter conversion
  Bar(&px); // 1
}
