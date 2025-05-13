template <typename T>
struct Foo {
  int use() {
    // return illegal_name; // CE, independent name
    // return T::illegal_name; // OK, dependent name
    return this->illegal_name;  // OK, dependent name
  }
};
