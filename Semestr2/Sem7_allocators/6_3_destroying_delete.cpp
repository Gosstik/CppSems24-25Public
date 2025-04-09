#include <iostream>
#include <memory>
#include <new>

// void operator delete(void* pa) {
//   std::cout << "1: " << pa << '\n';
//   free(pa);
//   // delete pa;
//   // delete pa;
// }

struct A {
 public:
  A() = default;

  void* operator new(size_t n) {  // static be default
    std::cout << "operator new for A\n";
    return malloc(n);
  }

  // void operator delete(void* ptr) {  // static by default
  //   std::cout << "operator delete for A\n";
  //   free(ptr);
  // }

  void operator delete(A* pa, std::destroying_delete_t) {
    pa->~A();
    std::cout << "2: " << pa << '\n';
    free(pa);
  }

  void Print() {  // NOLINT
    std::cout << "Print A\n";
  }

 private:
  ~A() {
    std::cout << "~A()\n";
  }
};

int main() {
  // A a;  // CE

  A* pa = new A();
  pa->Print();
  // delete pa; // CE
  A::operator delete(pa, std::destroying_delete);
}
