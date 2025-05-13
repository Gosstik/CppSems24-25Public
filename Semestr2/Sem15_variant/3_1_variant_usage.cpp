#include <iostream>
#include <string>
#include <variant>

// std::bad_variant_access

int main() {
  std::variant<int, double, std::string> v = 5;

  std::cout << std::get<int>(v) << '\n';

  v = 3.14;
  std::cout << std::get<double>(v) << '\n';

  v = "abc";
  std::cout << std::get<std::string>(v) << '\n';

  v = 'a';
  std::cout << std::get<int>(v) << '\n';

  // ambiguous
  std::variant<int, float> v2 = 2.0;
  std::variant<int, double> v3 = 2l;
}
