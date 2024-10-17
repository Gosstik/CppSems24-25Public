#include <iostream>
#include <format>

#define STUPID_MIN(a, b) a < b ? a : b

struct S {
 private:
  int x_ = 0;
  int xX = 0; // NOLINT
  int xXx = 0; // NOLINT(readability-identifier-naming)

 protected:
  int y_ = 5;

 public:
  int z = 10;
};

// NOLINTNEXTLINE(readability-function-size)
void Foo(int a, int b, int c, int d, int e, int f) {
  std::cout << a << b << c << d << e << f << std::endl;
  std::cout << a << '\n';
  std::cout << a << '\n';
  std::cout << a << '\n';
  std::cout << a << '\n';
  std::cout << a << '\n';
  std::cout << a << '\n';
  std::cout << a << '\n';
  std::cout << a << '\n';
  std::cout << a << '\n';
  std::cout << a << '\n';
  std::cout << a << '\n';
  std::cout << a << '\n';
  std::cout << a << '\n';
  std::cout << a << '\n';
  std::cout << a << '\n';
  std::cout << a << '\n';
  std::cout << a << '\n';
  std::cout << a << '\n';
  std::cout << a << '\n';
  std::cout << a << '\n';
  std::cout << a << '\n';
  std::cout << a << '\n';
  std::cout << a << '\n';
  std::cout << a << '\n';
  std::cout << a << '\n';
  std::cout << a << '\n';
  std::cout << a << '\n';
  std::cout << a << '\n';
  std::cout << a << '\n';
  std::cout << a << '\n';
  std::cout << a << '\n';
  std::cout << a << '\n';
  std::cout << a << '\n';
  std::cout << a << '\n';
  std::cout << a << '\n';
  std::cout << a << '\n';
  std::cout << a << '\n';
  std::cout << a << '\n';
  std::cout << a << '\n';
  std::cout << a << '\n';
  std::cout << a << '\n';
  std::cout << a << '\n';
  std::cout << a << '\n';
  std::cout << a << '\n';
  std::cout << a << '\n';
  std::cout << a << '\n';
  std::cout << a << '\n';
  std::cout << a << '\n';
  std::cout << a << '\n';
  std::cout << a << '\n';
  std::cout << a << '\n';
  std::cout << a << '\n';
  std::cout << a << '\n';
  std::cout << a << '\n';
  std::cout << a << '\n';
  std::cout << a << '\n';
  std::cout << a << '\n';
  std::cout << a << '\n';
  std::cout << a << '\n';
  std::cout << a << '\n';
  std::cout << a << '\n';
  std::cout << a << '\n';
  std::cout << a << '\n';
  std::cout << a << '\n';
  std::cout << a << '\n';
  std::cout << a << '\n';
  std::cout << a << '\n';
  std::cout << a << '\n';
  std::cout << a << '\n';
}

void Foo(int a, int b, int c, int d, int e, int f, int g) {
  std::cout << a << b << c << d << e << f << g << '\n';
}

// NOLINTBEGIN

void bar() {}
void baz() {}

// NOLINTEND

const double kPi = 3.14;

int main() {
  int x = 0;
  int* p = &x; // clang-analyzer-deadcode.DeadStores

  const char kHello[] = "Hello";

  std::cout << std::format("Hello, {}!\n", "world");
}
