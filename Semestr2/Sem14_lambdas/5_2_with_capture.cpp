// Use cppinsights

int main() {
  int c = 2;
  auto f = [c](int x, int y) { // &c, mutable
    return x + c < y;
  };
}
