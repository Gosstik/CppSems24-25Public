#include <iostream>

// Application: Initialize const variables


int main() {
  // Immediate invocation
  auto l = [] {
    return 0;
  }();

  []() {}();  // OK
  [] {}();    // OK
}
