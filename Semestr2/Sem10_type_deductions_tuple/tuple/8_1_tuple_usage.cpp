#include <iostream>
#include <tuple>

int main() {
  std::tuple<int, double, char> t1{1, 2.0, 'a'};
  std::tuple t2{1, 2.0, 'a'}; // CTAD

  auto& d1 = std::get<1>(t1);
  auto& d2 = std::get<1>(std::move(t1)); // CE, must save value type and const

  auto&& d3 = std::get<1>(std::move(t1)); // Nothing happened to t1.double
  auto d4 = std::get<1>(std::move(t1)); // Element 1 was moved
}