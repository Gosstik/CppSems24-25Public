#include <iostream>
#include <vector>

// When to use only v2?
// When to use both?

// // v1
template <typename T>
void Foo(T&) {
  // move/forward
  // copy
}

// v2
template <typename T>
void Foo(T&&) {
  // move/forward
  // move
}

int main() {}
