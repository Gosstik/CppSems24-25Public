#include <iostream>

int* Foo() {
  int* p = new int;
  return p;
}

int main() {
  // Variable
  int* p = new int;
  delete p;

  // Initialized variable
  int* pi = new int(100);
  delete pi;

  // Array
  int* ps = new int[100];
  delete[] ps;

  // Zero filled array
  int* pza = new int[100]{};
  delete[] pza;

  //! We are responsible for freeing the memory !!!
  int* get = Foo();
  *get = 10;
  delete get;
}
