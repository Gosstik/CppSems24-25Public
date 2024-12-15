#include <type_traits>

// https://en.cppreference.com/w/cpp/language/fold

////////////////////////////////////////////////////////////////////////////////

template <typename... Types>
struct AllPointers {
  static const bool value = (std::is_pointer_v<Types> && ...);
};

template <typename... Types>
constexpr bool all_pointers_v = AllPointers<Types...>::value;

////////////////////////////////////////////////////////////////////////////////

template <typename Head, typename ... Tail>
struct IsHomogeneous {
  static const bool value = (std::is_same_v<Head, Tail> && ...);
};

template <typename... Types>
constexpr bool is_homogeneous_v = IsHomogeneous<Types...>::value;

////////////////////////////////////////////////////////////////////////////////

// TODO: print

////////////////////////////////////////////////////////////////////////////////

int main() {
  static_assert(all_pointers_v<int*, double*, void**>);
  static_assert(!all_pointers_v<int*, double, void**>);
  static_assert(!all_pointers_v<int*, double*, void>);

  static_assert(is_homogeneous_v<int, int, int>);
  static_assert(!is_homogeneous_v<int, int, int, double>);
  static_assert(!is_homogeneous_v<double, int, int, double>);
}
