#include <iostream>
#include <vector>

// TODO: reference to cppreference

int main() {
  {
    int x = 0;
    decltype(x) y = x;
    std::vector<decltype(y)> v;
  }

  {
    int x = 0;
    int& y = x;
    decltype(y) z = y;  // int&
  }
}
