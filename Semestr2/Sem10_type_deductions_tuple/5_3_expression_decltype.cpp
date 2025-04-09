#include <iostream>

template <typename T>
void Debug() = delete;

int main() {
  {
    // decltype(expression)
    int x = 0;
    decltype(++x) u = x; // unevaluated context
    // decltype(x++) u = x;
    ++u;
    std::cout << x << u << '\n';  //* 11
  }

  {
    int x = 1;
    const decltype(throw 1)* px = &x; //* const void*
    // Debug<decltype(px)>();
  }

  {
    int x = 1;
    decltype((x)) y = x; // int&
    ++y;
    std::cout << x << y << '\n'; //* 22
  }
}
