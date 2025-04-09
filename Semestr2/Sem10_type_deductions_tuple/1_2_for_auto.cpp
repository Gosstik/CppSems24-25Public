#include <utility>

template <typename T>
void GetIterable(T&& c) {
  // wrapper that returns move_range or range conditionally
}

template <typename Container>
void Foo(Container&& c) {
  // mostly like you will want to use auto&& to support types
  // such as vector<bool>
  for (auto&& val: std::forward<Container>(c)) {
    // support ref qualifiers in c.begin() and c.end()
    // ...
  }

  // More likely
  for (auto&& val: GetIterable(std::forward<Container>(c))) {
    // support ref qualifiers in c.begin() and c.end()
    // ...
  }
}
