#include <iostream>
#include <iterator>
#include <list>
#include <vector>

template <std::input_iterator Iter>
void Advance(Iter& it, size_t n) {
  for (size_t i = 0; i < n; ++i) {
    ++it;
  }
}

template <std::random_access_iterator Iter>
void Advance(Iter& it, size_t n) {
  it += n;
}

int main() {
  std::vector<int> v(5, 1);
  auto vit = v.begin();
  Advance(vit, 2);

  std::list<int> l(5);
  auto lit = l.begin();
  Advance(lit, 2);
}
