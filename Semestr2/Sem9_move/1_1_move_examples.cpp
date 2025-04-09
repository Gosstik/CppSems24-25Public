#include <iostream>
#include <string>

// If object is rvalue --- compiler calls move ctor
// If object is lvalue --- compiler calls copy ctor
// std::move(val) --- force compiler treat val as rvalue. It returns T&&

// For primitive types move is useless !!!

// What if call std::move() without acquiring value ???

int main() {
  {
    int x = 1;     //* OK
    int&& y = 2;   //* OK
    int&& z1 = y;  //* CE

    int&& z2 = std::move(y);           //* OK
    int&& z3 = static_cast<int&&>(y);  //* OK
    int&& z4 = (int&&)y;               //* OK

    z2 = 0;                  //* OK
    std::cout << y << '\n';  //* 0
  }

  {
    int&& x = 2;             //* OK
    int& y = x;              //* OK
    int&& z = std::move(x);  //* OK
    y = 3;                   //* OK
    ++y;                     //* OK
    std::cout << x << y << '\n'; // 4 4
  }

  {
    int&& a = 3;                   //* OK
    const int&& b = std::move(a);  //* OK
    const int& c = b;              //* OK

    const int&& d = 2;  //* OK
  }

  {
    int x = 0;
    // CE, expression must always have the same type
    int& y1 = (true) ? ++x : x++;
    int&& y2 = (true) ? ++x : x++; // OK
  }
}
