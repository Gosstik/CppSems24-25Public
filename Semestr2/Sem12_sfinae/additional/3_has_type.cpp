#include <type_traits>

template <typename T, typename = void>
struct HasInnerType: std::false_type {};

template <typename T>
struct HasInnerType<T, std::void_t<typename T::Inner>>: std::true_type {};

template <typename T>
static constexpr bool HasInnerTypeV = HasInnerType<T>::value;

////////////////////////////////////////////////////////////////////////////////

struct A {
  using Inner = int;
};

struct B {
  struct Inner {};
};

struct C {
  struct Outer {};
};


static_assert(HasInnerTypeV<A>);
static_assert(HasInnerTypeV<B>);
static_assert(!HasInnerTypeV<C>);
