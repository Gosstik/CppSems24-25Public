#include <iostream>
#include <type_traits>
#include <vector>

// TODO

// type_identity<T>
// integral_constant<T, V>
// bool_constant<Bool>, true_type, false_type

// is_lvalue_reference

//// Wrong implementation. Correct impl must be lazy (short-circuiting)
template <typename... Types>
struct conjunction {  // NOLINT(readability-identifier-naming)
  static constexpr bool value = (... && Types::value);
};

// disjunction
// negation

//// What means compilation error: expected primary-expression ???
// Compiler expected expression, but get type or something else. Occurs when
// instead of _v we by mistake use meta class.

////////////////////////////////////////////////////////////////////////////////

int main() {
  // TODO
}
