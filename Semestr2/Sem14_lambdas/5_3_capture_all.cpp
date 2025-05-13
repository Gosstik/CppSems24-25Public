// Use cppinsights

int main() {
  int c1 = 1;
  int c2 = 2;
  auto f = [=](int x, int y) {
    return x + c1 < y;
  };
}
