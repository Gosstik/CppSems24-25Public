#include <algorithm>
#include <map>
#include <string>

// Closure is not a template, template is operator()

// https://en.cppreference.com/w/cpp/language/lambda

int main() {
  std::map<std::string, int> m;
  m["abc"] = 1;
  m["cde"] = 2;

  decltype(m) m2;

  auto f1 = [](auto& item) {
    ++item.second;
    return item;
  };

  std::transform(m.begin(), m.end(), std::inserter(m2, m2.begin()), f1);

  // generalized lambda since c++20
  // attribute since c++23
  auto f2 = []<typename T> [[nodiscard]] (T & item) {
    ++item.second;
    return item;
  };
}
