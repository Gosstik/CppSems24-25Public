#include <iostream>
#include <string>

// both of [=] and [&] are bad code style

struct A {
  A() {
    std::cout << "A()\n";
  }

  A(int a) : val(a) {
    std::cout << "A(int)\n";
  }

  A(const A&) {
    std::cout << "copy\n";
  }

  A(A&&) noexcept {
    std::cout << "move\n";
  }

  int val;
};

int main() {
  A a1{1};
  A a2{2};

  auto lc = [=] {
    // std::cout << a1.val << ' ' << a2.val << '\n';  // copy x2
    // std::cout << a1.val << '\n';                   // copy x1
    return true;                                   // no copy
  };

  // l();  // copies in capture list will be even without call

  //////////////////////////////////////////////////////////////////////////////

  auto lr = [&] {
    std::cout << a1.val << ' ' << a2.val << '\n';  // no copy
  };
}
