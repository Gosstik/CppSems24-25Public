#include <iostream>
#include <vector>

template <typename T>
void Foo(T) {

}

template <typename T>
void Foo(T&&) {

}

int main() {
  std::vector<bool> vec(10);
  for (auto&& v: vec) {
    v = true;

  }
}
