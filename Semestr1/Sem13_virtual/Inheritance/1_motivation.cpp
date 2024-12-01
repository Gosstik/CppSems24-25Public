#include <iostream>

// Motivation: solve diamond problem (no duplicated parents)

struct Granny {
  int g;
};

struct Mom: virtual Granny { // NOLINT
  int m;
};

struct Dad: virtual Granny { // NOLINT
  int d;
};

struct Son: Mom, Dad { // NOLINT
  int s;
};

int main() {
  std::cout << sizeof(Son) << '\n';
}
