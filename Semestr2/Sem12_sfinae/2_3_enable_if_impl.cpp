#include <type_traits>
#include <iostream>

// enable_if == is_same, but without second type

template <bool B, typename T = void>
struct EnableIf {};

template <typename T>
struct EnableIf<true, T> {
  using type = T; // NOLINT
};

template <bool B, typename T  = void>
using EnableIfT = EnableIf<B, T>::type;

////////////////////////////////////////////////////////////////////////////////

// Redefinition
// Name lookup shows that signatures differs only by default argument
// Substitution of default arguments occurs after name lookup

// template <typename T, typename = EnableIfT<std::is_integral_v<T>>>
// auto Foo(T val) {
//   std::cout << "integral value: " << val << '\n';
// }

// template <typename T, typename = EnableIfT<!std::is_integral_v<T>>>
// auto Foo(T val) {
//   std::cout << val << '\n';
// }

////////////////////////////////////////////////////////////////////////////////

// Solution

// Name lookup is deferred until template substitution

template <typename T, EnableIfT<std::is_integral_v<T>, bool> = true>
auto Bar(T val) {
  std::cout << "integral value: " << val << '\n';
}

// Does not work, redefinition (differs only by default argument)
template <typename T, EnableIfT<!std::is_integral_v<T>, bool> = true>
auto Bar(T val) {
  std::cout << val << '\n';
}

////////////////////////////////////////////////////////////////////////////////

// Example above:
// https://en.cppreference.com/w/cpp/types/enable_if#Notes

int main() {
  Bar(10);
  Bar("abc");
}
