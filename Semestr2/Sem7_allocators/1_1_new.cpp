#include <iostream>
#include <vector>
#include <string>

// new (operator) consists of two phases:
// 1) Allocates memory (operator new)
// 2) Calls ctor (placement new)

// All versions of operator new
// https://en.cppreference.com/w/cpp/memory/new/operator_new

// What version uses vector (new or new[]) ???

void* operator new(size_t n) {
  std::cout << n << " bytes allocated\n";
  return malloc(n);
}

void operator delete(void* ptr) noexcept {
  std::cout << "delete\n";
  free(ptr);
}

// Try to comment new[] and delete[] and disable sanitizers :)

void* operator new[](size_t n) {
  std::cout << n << "[] bytes allocated\n";
  return malloc(n);
}

void operator delete[](void* ptr) noexcept {
  std::cout << "delete[]\n";
  free(ptr);
}

///////////////////////////

// TODO: remove Base

struct Base {
  Base() { std::cout << "Base()\n"; }
  virtual ~Base() { std::cout << "~Base()\n"; }
};

struct Derived {
  int* p;
  Derived() {
    std::cout << "Derived()\n";
    p = new int(0);
  }
  ~Derived() {
    std::cout << "~Derived()\n";
    delete p;
  }
};

///////////////////////////

int main() {
  {
    int* a = new int(1);
    delete a;

    int* arr = new int[10]{};
    delete[] arr;
  }

  // {
  //   std::vector<int> v;
  //   for (int i = 0; i < 50; ++i) {
  //     v.push_back(i);
  //   }
  // }

  //// Additional 8 bytes are used for count of dtors to call
  // {
  //   std::cout << sizeof(std::string) << '\n'; // out: 32
  //   std::string* ps = new std::string[10]("abccccccccccccccccccccccccccccccccccccccccccc", "abcccccccccccccccccccccc"); // NOLINT // out: 328 = 320 + 8
  //   delete[] ps;

  //   std::string* ps1 = new std::string[1]; // NOLINT // out: 40 = 32 + 8
  //   delete[] ps1;
  // }
}