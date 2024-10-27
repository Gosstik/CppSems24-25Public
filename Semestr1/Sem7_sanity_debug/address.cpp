#include <iostream>
#include <string>

int main() {
  const char* p = "start"; //* use std::string_view
  {
    std::string str = "abc"; //* make it long to prevent sso
    p = str.c_str();
  }
  std::cout << p << '\n';
}
