// open /usr/include/c++/13/bits/basic_string.h

#include <string>

int main() {
  static_assert(sizeof(std::string) == 32);
}
