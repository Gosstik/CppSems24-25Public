#include <algorithm>
#include <cstring>
#include <initializer_list>
#include <iostream>
#include <vector>

// order in member initializer list is important !!!

class Complex {
 public:
  //  Complex(double real) {
  //    re = real;
  //    // this->re = re;
  //  }

  Complex(double re) : re_(re) {}
  Complex(double re, double im) : re_(re), im_(im) {}

 private:
  double re_ = 0.0;
  double im_ = 0.0;
};

class String {
 public:
  // since C++11
  String(std::initializer_list<char> list)
      : data_(new char[list.size() + 1]),
        size_(list.size()),
        cap_(size_) {
    std::copy(list.begin(), list.end(), data_);
    data_[size_] = '\0';
  }

  ~String() { delete[] data_; }

 private:
  char* data_ = nullptr;
  size_t size_ = 0;
  size_t cap_ = 0;
};

// See on cppreference:
// List initialization
// Aggregate initialization
// Direct initialization
// Value initialisation
// ...

int main() {
  {
    // possible construction
    Complex c(5.0);      // ?
    Complex c2 = 5.0;    // ?
    Complex c3{5.0};     // Uniform initialization
    Complex c4 = {8.0};  // Aggregate initialization
  }

  {
    // what ctor and what is the difference?
    std::vector<int> v1 = {1, 2, 3, 4, 5};
    std::vector<int> v2{1, 2, 3, 4, 5};
  }

  {
    // initializer_list problem
    String s1 = {'a', 'b'};
    String s2{2, 'a'};  //* what ctor to call? --- initializer_list
  }
}
