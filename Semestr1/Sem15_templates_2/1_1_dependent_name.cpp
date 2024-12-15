#include <array>
#include <iostream>

template <typename T>
struct Base {
  int x = 0;
};

template <>
struct Base<double> {
  //  int x = 0;
};

template <typename T>
struct Derived : Base<T> {
  void Foo() {
    ++x;           // CE
    ++Base<T>::x;  // OK
    ++Base::x;     // CE
    ++this->x;     // OK
  }
};

int main() {
  
}
