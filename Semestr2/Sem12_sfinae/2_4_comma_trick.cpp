#include <type_traits>
#include <vector>

namespace detail {

template <typename T>
std::true_type HasSizeTypeImpl(decltype(typename T::size_type{}, nullptr));

//// same effect as above
// template <typename T>
// auto HasSizeTypeImpl(void*) -> decltype(typename T::size_type{}, std::true_type{});

template <typename...>  // ! Must be template
std::false_type HasSizeTypeImpl(...);

}  // namespace detail

template <typename T>
struct HasSizeType : decltype(detail::HasSizeTypeImpl<T>(nullptr)) {};

template <typename T>
constexpr bool has_size_type_v = HasSizeType<T>::value;

////////////////////////////////////////////////////////////////////////////////

static_assert(!has_size_type_v<int>);
static_assert(has_size_type_v<std::vector<int>>);

int main() {}
