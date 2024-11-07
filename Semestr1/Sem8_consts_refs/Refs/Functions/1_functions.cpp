int& Foo(int& x) {
  return ++x;
}

int main() {
  int x = 0;
  Foo(x) = 2;
  int& rt = Foo(x);
  int t = Foo(x); //* lvalue to rvalue conversion
  // *p = *p2; //* also lvalue to rvalue conversion
}
