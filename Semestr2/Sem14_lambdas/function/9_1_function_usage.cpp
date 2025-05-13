#include <functional>
#include <iostream>

int Add1(int a) {
  return a + 1;
}

struct Add2 {
  int operator()(int a) {
    return a + 2;
  }
};

int main() {
  std::function<int(int)> f = Add1;
  std::cout << f(0) << '\n';

  f = Add2();
  std::cout << f(0) << '\n';

  f = [](int a) {
    return a + 3;
  };
  std::cout << f(0) << '\n';

  auto f2 = f; // copy ctor
  f = f2; // !!! Also must compile in contrast to lambdas
}
