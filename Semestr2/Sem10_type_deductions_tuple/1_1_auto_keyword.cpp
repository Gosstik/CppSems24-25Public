#include <iostream>
#include <type_traits>

// Same deduction rules as in template <typename T> Foo(T x) {}

int main() {
  {
    auto x = 1;
    auto& rx = x;
    const auto& crx = x;
    auto&& t = x;              // as universal reference
    auto&& t2 = std::move(x);  // as universal reference
  }

  {
    int* p = new auto(5);
    delete p;
  }
}
