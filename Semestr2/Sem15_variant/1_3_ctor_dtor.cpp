#include <iostream>
#include <string>

// https://en.cppreference.com/w/cpp/language/union

union U {
  int x;
  std::string s;

  U() {}  // default init with first field
  ~U() {}
};

int main() {
  U u;

  u.x = 1;
  std::cout << u.x << '\n';

  // u.s = "abc"; // UB
  new (&u.s) std::string("abc");  // OK
  std::cout << u.s << '\n';

  u.s.~basic_string<char>(); // memory leak without this line
  u.x = 3;
}
