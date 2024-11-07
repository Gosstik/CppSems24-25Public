struct Base {
 private:  // try to comment
  double d;
  int x;
};

struct Derived : public Base {
  int y;
};

static_assert(sizeof(Derived) == 16);
