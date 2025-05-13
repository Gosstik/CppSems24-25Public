#include <iostream>

// functional programming

int main() {
  auto sum = [](int x, int y) {
    return x + y;
  };

  auto fix_second = [](auto f, auto arg2) {
    return [f, arg2](auto arg1) {
      return f(arg1, arg2);
    };
  };

  // auto fix_second_2 = [](auto&& f, auto&& arg2) {
  //   return [f = std::forward<decltype(f)>(f),
  //           arg2 = std::forward<decltype(arg2)>(arg2)](auto&& arg1) {
  //     return f(std::forward<decltype(arg1)>(arg1), arg2);
  //   };
  // };

  auto sum_10 = fix_second(sum, 10);
  std::cout << sum_10(5) << '\n';  // 15
}
