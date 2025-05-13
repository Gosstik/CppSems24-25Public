template <typename T>
struct Base {
  void exit();
};

template <typename T>
struct Derived : Base<T> {
  void foo() {
    exit();  // not Base::exit(), it is not dependent name => use global exit()
    // Base::exit(); // CE
    Base<T>::exit();  // OK
    this->exit();     // OK
  }
};

// !!! typename and template must be used only with dependent names
