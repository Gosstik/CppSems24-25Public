#include <iostream>

template <typename... Ts>
class Variant;

////////////////////////////////////////////////////////////////////////////////

template <typename... Ts>
struct GetIndexByType {
  static const size_t value = 0; // TODO
};

////////////////////////////////////////////////////////////////////////////////

template <typename T, typename... Types>
struct VariantAlternative {
  // TODO: handle same types
  static constexpr size_t kIndex = GetIndexByType<T, Types...>::value;


  VariantAlternative() = default;

  VariantAlternative(const T& value) {
    auto* this_variant = static_cast<Variant<Types...>*>(this);
    new (this_variant->buffer) T(value);
    this_variant->active_index = kIndex;
  }
  // TODO: move ctor

  // !!! Cannot be done in dtor of VariantAlternative
  void Destroy() {
    auto* this_variant = static_cast<Variant<Types...>*>(this);
    if (this_variant->active_index == kIndex) {
      reinterpret_cast<T*>(this_variant->buffer)->~T();
    }
  }
};

////////////////////////////////////////////////////////////////////////////////

template <typename... Types>
union VariadicUnion;

template <typename Head, typename... Tail>
union VariadicUnion<Head, Tail...> {
  Head head;
  VariadicUnion<Tail...> tail;
};

template <typename Head>
union VariadicUnion<Head> {
  Head head;
};

////////////////////////////////////////////////////////////////////////////////

template <typename Head, typename... Tail>
struct MaxTypeSize {
  static const size_t value = std::max(sizeof(Head), MaxTypeSize<Tail...>::value);
};

template <typename Head>
struct MaxTypeSize<Head> {
  static const size_t value = sizeof(Head);
};

////////////////////////////////////////////////////////////////////////////////

template <typename... Types>
class Variant : private VariantAlternative<Types, Types...>... {
 public:
  using VariantAlternative<Types, Types...>::VariantAlternative...;

  ~Variant() {
    (VariantAlternative<Types, Types...>::destroy(), ...);
  }

 private:
  template <typename T, typename... Ts>
  friend struct VariantAlternative;

  // VariadicUnion<Types...> varun; // Option 1
  // TODO: alignment
  // TODO: buffer must be in first parent !!!
  char buffer[MaxTypeSize<Types...>::value]; // Option 2
  size_t active_index_;
};

////////////////////////////////////////////////////////////////////////////////

// std::visit

// private method in VariantAlternative
// Several variants is table
// What is return type? --- decltype(func_to_call)

////////////////////////////////////////////////////////////////////////////////

int main() {
  static_assert(MaxTypeSize<int, double, char>::value == 8);
  static_assert(MaxTypeSize<int, char>::value == 4);
  static_assert(MaxTypeSize<char>::value == 1);
}
