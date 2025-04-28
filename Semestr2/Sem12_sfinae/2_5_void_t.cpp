#include <type_traits>

// TODO (e.g. in common type)

template <typename...>
using void_t = void;

template <typename...>
struct smart_void_t : std::type_identity<void> {};

////////////////////////////////////////////////////////////////////////////////

template <typename T, std::void_t<typename T::First>* = nullptr>
int Foo() {
  return 1;
}

template <typename T, std::void_t<typename T::Second>* = nullptr>
int Foo() {
  return 2;
}

template <typename T, smart_void_t<typename T::First>* = nullptr>
int SmartFoo() {
  return 1;
}

template <typename T, smart_void_t<typename T::Second>* = nullptr>
int SmartFoo() {
  return 2;
}

struct One {
  using First = int;
};

struct Two {
  using Second = int;
};

int main() {
  auto i1 = Foo<One>();       // CE
  auto i2 = Foo<Two>();       // CE
  auto j1 = SmartFoo<One>();  // OK
  auto j2 = SmartFoo<Two>();  // OK
}
