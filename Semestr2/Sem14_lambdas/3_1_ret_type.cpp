

// auto by default

int main() {
  auto l = [](int x, int y) -> int {
    if (x < y) {
      return 0;
    }
    return 1u;
  };

  //////////////////////////////////////////////////////////////////////////////

  auto inc = [](int& x) -> decltype(auto) {
    ++x;
    return x;
  };

  int x = 0;
  int& y = inc(x);
}
