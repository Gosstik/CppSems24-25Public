#include <iostream>

// https://en.cppreference.com/w/cpp/language/user_literal

struct Latitude {
  double val;
  explicit Latitude(double val) : val(val) {}

  explicit operator double() const { return val; }
};

// -1234_mysuf == operator-(1234_mysuf)

Latitude operator""_lat(long double d) {
  return Latitude(d);  // NOLINT
}

// tests

void Foo(Latitude lat) {
  std::cout << "Insode Foo: ";
  std::cout << lat.val << '\n';
}

int main() {
  {
    Latitude lat1 = 1.0_lat;
    std::cout << lat1.val << '\n';

    Foo(3.0_lat);
  }
}
