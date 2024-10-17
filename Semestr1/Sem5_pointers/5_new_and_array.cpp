#include <iostream>

int* Foo() {
  int* p = new int;
  return p;
}

int main() {
  {
    // Variable
    int* p = new int;
    delete p;

    // Initialized variable
    int* pi = new int(100);
    delete pi;

    // Array
    int* ps = new int[100];
    // int psa[100] = new int[100]; // CE
    // std::cout << ps[-2] << '\n'; // same as vector
    delete[] ps;

    // Zero filled array
    int* pza = new int[100]{};
    delete[] pza;

    // Const zero filled array (rarely used)
    const int* cpza = new int[100]{};
    delete[] cpza;

    //! We are responsible for freeing the memory !!!
    int* get = Foo();
    *get = 10;
    delete get;
  }

  {
    // Pointers may be reused after delete
    int* rp = new int(10);
    delete rp;
    rp = new int(20);
    delete rp;
  }

  {
    // UB: size of dynamic array
    int* p1 = new int[100];
    int* p2 = new int[1000];
    int* p3 = new int[4000];
    std::cout << p1[-2] << ' ' << p2[-2] << ' ' << p3[-2] << '\n';
  }
}
