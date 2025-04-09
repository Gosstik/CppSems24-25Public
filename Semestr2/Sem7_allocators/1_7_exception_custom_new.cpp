#include <cstddef>
#include <cstdlib>
#include <iostream>

// Try to comment custom operator delete

void* operator new(size_t n, int a, double b) {
  std::cout << n << " bytes allocated with custom new " << a << ' ' << b
            << '\n';
  return malloc(n);
}

// void operator delete(void* ptr, int a, double b) noexcept {
//   std::cout << "custom delete called " << a << ' ' << b << '\n';
//   free(ptr);
// }

struct S {
  S() { throw 1; }
};

int main() {
  try {
    S* p = new(1, 3.14) S(); // compiler must call appropriate delete
  } catch(...) {
    std::cout << "caught!\n";
  }
}
