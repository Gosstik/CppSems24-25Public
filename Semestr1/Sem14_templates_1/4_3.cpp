#include <iostream>

template <typename T>
struct Main {
  template <typename V>
  struct Inner {
    template <typename U>
    void Foo();
  };
};

template <typename T>
template <typename V>
template <typename U>
void Main<T>::Inner<V>::Foo() {}

int main() {}
