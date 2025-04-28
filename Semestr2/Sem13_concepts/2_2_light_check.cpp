#include <algorithm>
#include <vector>

// std::sort does not have requirements yet, body is not instantiated

template <typename T>
  requires requires(T a, T b) { std::sort(a, b); }
void Foo(T first, T last) {}

int main() {
  std::vector<int> v = {1, 2, 3, 4, 5};
  Foo(v.begin(), v.end());  // OK
  Foo(1, 2);                // OK
}
