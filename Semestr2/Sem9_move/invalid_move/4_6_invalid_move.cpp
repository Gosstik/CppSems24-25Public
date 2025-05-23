#include <type_traits>

template <typename T>
T&& move(const T& x) { // NOLINT(readability-identifier-naming)
  return static_cast<T&&>(x);
}

////////////////////////////////////////////////////////////////////////////////

void Rvalue(int&&) {}

int main() {
  int x = 1;

  // Rvalue(move(x));        // 1
  // Rvalue(move(1));        // 2
  // Rvalue(move<int&>(x));  // 3
}
