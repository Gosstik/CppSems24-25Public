#include <iostream>

#include "other.hpp"

// ODR - One Definition Rule

// int Foo() {
//   return 21;
// }

// int Foo();

int main() {
	int a = 0;
  int b = 1;
  std::cout << a + b << std::endl;
  std::cout << Foo() << '\n';
}

// mov eax, 1
// add eax, 1
