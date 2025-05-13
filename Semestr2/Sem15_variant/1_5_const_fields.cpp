#include <iostream>

union U {
  const int x;
  double y;
};

int main() {
  U u;
  // u.x = 1; // CE

  u.y = 1.0; // OK
  new (&u) int(1); // OK
}
