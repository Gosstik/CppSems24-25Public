#include <iostream>

int main() {
  auto l = [] { // no ()
    return 0;
  };

  l();
}
