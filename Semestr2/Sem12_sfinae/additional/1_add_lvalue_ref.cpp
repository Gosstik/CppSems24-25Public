#include <type_traits>

// Simple, but not working example

template <typename T>
struct AddLRef {
  using type = T&;
};

// Still do not work

template <>
struct AddLRef<void> {
  using type = void;
};

// Better

// use std::remove_cv_t and Impl

// More suitable solution is to use SFINAE

namespace detail {

template <typename T, typename Enable>
struct Impl {
  using type = T;
};

template <typename T>
struct Impl<T, std::remove_reference_t<T&>> {
  using type = T&;
};

} // namespace detail

template <typename T>
struct SmartAddLRef {
  using type = detail::Impl<T, std::remove_reference_t<T>>::type;
};
