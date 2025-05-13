#include <iostream>

struct A {
  int a = 3;
  auto GetF() const {
    // a is not local variable => it is not captured
    // this is captured instead
    auto f = [=](int x) {
      return x + a;
    };
    return f;
  }
};

struct B {
  int a = 3;
  auto GetF() const {
    // auto f1 = [a](int x) {  // CE
    //   return x + a;
    // };
    auto f2 = [this](int x) {  // explicit capture by pointer
      return x + a;
    };
    auto f3 = [a = a](int x) {  // capture by value !!!
      return x + a;
    };
    return f3;  // OK
  }
};

int main() {
  A* a = new A();
  auto f = a->GetF();
  delete a;

  std::cout << f(5) << '\n';  // UB
}
