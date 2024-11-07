#include <iostream>

enum /*class*/ E {
  White = 1,
  Gray,
  Black = 1,
};

int main() {
  int e = White;
  // E e = E::White;
  std::cout << e << '\n';

  // int64_t e = E::Black;
  // E e = E::White;
  // std::cout << e << '\n';
  std::cout << (E::White == E::Black) << '\n';
}
