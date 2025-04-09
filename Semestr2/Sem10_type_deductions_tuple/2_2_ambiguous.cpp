// Type conversion does not work for deduction
auto Foo(int x) {
  if (x > 0) {
    return 1;
  }
  return 1u;
}

int main() {
  // TODO
}
