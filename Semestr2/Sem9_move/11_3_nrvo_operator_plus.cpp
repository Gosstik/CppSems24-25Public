#include <iostream>
#include <utility>

struct S {
  S(int x) : x(x) {
    std::cout << "S(int)\n";
  }
  S(const S& other) : x(other.x) {
    std::cout << "S(copy)\n";
  }
  S(S&& other) : x(other.x) {
    std::cout << "S(move)\n";
  }
  ~S() {
    std::cout << "~S()\n";
  }

  S& operator+=(const S& other) {
    x += other.x;
    return *this;
  }

  int x;
};

S operator+(const S& lhs, const S& rhs) {
  S res(lhs);
  res += rhs;
  return res; // NRVO
}

// S operator+(S lhs, const S& rhs) {
//   lhs += rhs;
//   return lhs;
// }

S operator+(S&& lhs, const S& rhs) {
  lhs += rhs;
  return std::move(lhs);
}

void Foo(const int&) {}
void Foo(int&) {}
void Foo(int&&) {}

int main() {
  S sum = S(1) + S(2);

  int x;
  Foo(1);
}
