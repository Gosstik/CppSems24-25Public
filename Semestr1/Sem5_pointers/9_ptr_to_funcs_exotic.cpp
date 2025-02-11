#include <iostream>

void Foo(int) {}

// Function returning function
void (*Bar(int))(int) { return Foo; }

int main() {
  // Read precedence:
  // 1) inside braces
  // 2) right part
  // 3) left part
  // Simple rule: go right when you can, go left when you must
  // More examples with explanation:
  // http://www.unixwiz.net/techtips/reading-cdecl.html

  void (*pf)(int);       // ptr to f
  void (*pfa[10])(int);  // Array of 10 ptrs to functions

  void (*(*pff[10])(int))(int);    // ???
  size_t** e1[7];                  // ???
  int (*(*e2)(double, int))(int);  // ???
  int (*(*e3)())(int);             // ???
  int (*e4())(int) = nullptr;      //! function declaration !!!!!!!
  int a = 0;
  int ((b)) = 4;

  char*(*(**foo[][8])())[] = {};  // ???????????????????????????????
}
