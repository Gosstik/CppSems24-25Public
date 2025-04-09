#include <iostream>
#include <utility>

// Copy elision and rvo, guaranteed copy elision
// https://en.cppreference.com/w/cpp/language/copy_elision

struct S {
  S(int x) : x(x) {
    std::cout << "S(int)\n";
  }
  S(const S& other) : x(other.x) {
    std::cout << "S(copy)\n";
  }
  S(S&& other) : x(other.x) {
    std::cout << "S(move)\n";
  }
  ~S() {
    std::cout << "~S()\n";
  }

  int x;
};

S Foo(S s) {
  return s; //* move ctor is called
}

S Bar(S&& s) {
  return std::move(s); // case when std::move is reasonable
}

int main() {
  //// S(int) ~S()
  // S s1 = S(S(S(S(S(1)))));

  //// S(int) S(move) ~S() ~S()
  // S s2 = std::move(S(S(S(S(S(1)))))); // rvalue -> xvalue

  //// Will create S at least once even if result is unused
  // S(S(S(S(S(1)))));

  //// Accessing class members causes rvalue -> xvalue
  // S s3 = S(S(1).x); // calls S(int) twice

  //// Even if compiler cannot make RVO, it tries to call move ctor
  // S s4 = Foo(S(1));

  //// s is reference inside bar, without std::move there will be copy
  S s5 = Bar(S(1));
}
