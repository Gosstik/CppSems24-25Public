#include <iostream>

// sizeof(union) = max(T)
// sizeof(struct) = sum(T)

union U {
  int x;
  double y;
};

int main() {
  U u;
  u.x = 1;
  std::cout << u.x << '\n';  // 1
  u.y = 2.0;
  std::cout << u.y << '\n';  // 2

  std::cout << u.x << '\n';  // 0 ???
}
