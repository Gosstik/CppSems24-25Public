#include <iostream>

auto factory(int p) {
  static int a = 0;
  return [=](int arg) { // replacing = with & causes UB
    static int b = 0;
    a += p;
    b += arg;
    return a + b;
  };
}

int main() {
  auto f1 = factory(1);
  auto f2 = factory(2);

  std::cout << f1(20) << " " << f1(30) << " " << f2(20) << " " << f2(30)
            << '\n';  // 21 52 74 106
}
