#include <algorithm>
#include <map>

// Closure is not a template, template is operator()

int main() {
  auto f = [](auto item)
    requires requires(decltype(item) a) { ++a.second; }
  {
    ++item.second;
    return item;
  };

  std::map<int, int> m;
  std::map<int, int> m2;
  std::transform(m.begin(), m.end(), std::inserter(m2, m2.begin()), f);
}
