#include <cstdint>
#include <iostream>
#include <string>

// Anonymous union

struct IntWrapper {
  bool is_parsed;
  union {
    int v;
    const char* s;
  };
};

double GetInt(IntWrapper& ch) {
  if (ch.is_parsed) {
    return ch.v;
  }
  return std::stoi(ch.s);
}

////////////////////////////////////////////////////////////////////////////////

// Anonymous struct

union U {
  uint32_t i;
  struct { // C-language feature, compiler extension for C++
    char b1;
    char b2;
    char b3;
    char b4;
  };
};

////////////////////////////////////////////////////////////////////////////////

int main() {
  U u{
      .i = 1 + (1 << 9) + (1 << 18) + (1 << 27),
  };

  // UB
  std::cout << int(u.b1) << ' ' << int(u.b2) << ' ' << int(u.b3) << ' '
            << int(u.b4) << '\n';
}
