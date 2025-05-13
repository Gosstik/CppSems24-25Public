#include <iostream>
#include <string>

union U {
  int x;
  std::string s;

  U() {} // default init with first field
  ~U() {}
};

int main() {
  //// no default ctor
  // U u; // CE

  //// no default dtor
  // U u { // CE
  //   .s = "abc",
  // };
}
