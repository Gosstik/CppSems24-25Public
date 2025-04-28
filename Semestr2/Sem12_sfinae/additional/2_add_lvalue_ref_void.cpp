#include <type_traits>

// More suitable solution is to use SFINAE

namespace detail {

template <typename T, typename Enable>
struct Impl {
  using type = T;
};

template <typename T>
struct Impl<T, std::void_t<T&>> {
  using type = T&;
};

} // namespace detail

template <typename T>
struct SmartAddLRef {
  using type = detail::Impl<T, void>::type;
};
