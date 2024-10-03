#include <iostream>
#include <iostream>

#include "util.hpp"
// #include "util.hpp"

// #include "header_no_guard.hpp"
// #include "header_no_guard.hpp"

#include "header_guard.hpp"
#include "header_guard.hpp"

// #include "header_pragma.hpp"
// #include "header_pragma.hpp"

int main() {
  {
    PrintHelloWorld();
    std::cout << GetSquare(5);
  }

  // {
  //   int x = 40;
  //   std::cout << HeaderFunc(2) << '\n';
  // }
}
