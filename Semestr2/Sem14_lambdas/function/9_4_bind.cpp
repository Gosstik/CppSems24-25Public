#include <functional>
#include <iostream>

// It is better to use lambda to std::bind
// clang-tidy: modernize-avoid-bind

template <typename T>
void Debug() = delete;

int Diff(int x, int y) {
  return x - y;
}

int main() {
  auto f = std::bind(Diff, std::placeholders::_1, 5);
  std::function<int(int)> f2 = std::bind(Diff, std::placeholders::_1, 5);  // !
  std::cout << f(5) << '\n';                                               // 0

  //// [with T = std::_Bind<int (*(int, std::_Placeholder<1>))(int, int)>]
  // Debug<decltype(f)>();
}
