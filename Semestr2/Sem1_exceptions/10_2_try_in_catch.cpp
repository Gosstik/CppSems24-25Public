#include <iostream>
#include <new>

// How to allocate memory for std::bad_alloc in case new threw it?
//* it is preallocated in static memory

int main() {
  try {
    throw std::bad_alloc();
  } catch (const std::bad_alloc& e1) {
    try {
      throw std::bad_alloc();
    } catch(const std::bad_alloc& e2) {
      std::cout << &e1 << '\n' << &e2 << '\n'; // different addresses
    }
  }
}
