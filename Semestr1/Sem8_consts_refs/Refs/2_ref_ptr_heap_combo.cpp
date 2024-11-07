
// OK, CE, RE, UB ???

int& Foo() {
  int* p = new int;
  return *p;
}

int main() {
  int x = Foo();
  // int& x = Foo();
  delete &x;
}
