#include <iostream>
#include <string>
#include <utility>

// Capture with initialization

int main() {
  int a = 1;
  auto cap_int = [a = a + 1]() {
    std::cout << a << '\n';
  };

  //////////////////////////////////////////////////////////////////////////////

  std::string s = "hello";
  auto cap_move = [str = std::move(s)]() {
    std::cout << str << '\n';
  };

  //////////////////////////////////////////////////////////////////////////////

  bool bv = true;
  // auto cap_const_ref = [&bv = std::as_const(bv)]() {
  auto cap_const_ref = [&bv = (const bool&)(bv)]() {
    std::cout << bv << '\n';
  };

  //////////////////////////////////////////////////////////////////////////////

  // bool test = true;
  // auto cap_ce= [&bv = std::move(test)]() {
  //   std::cout << bv << '\n';
  // };
}
