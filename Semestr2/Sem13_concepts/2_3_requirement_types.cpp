#include <vector>

// 1) Simple requirements
// 2) Nested requirements (use requires inside requires)
// 3) Type requirements
// 4) Compound requirements (with concepts, will be later)

//// 1) Simple requirements
template <typename T, int N>
  requires requires { sizeof(T) == N; }  // check just compile, not value
void Foo() {}

//// 2) Nested requirements
template <typename T, int N>
  requires requires {
    requires sizeof(T) == N;
  }
void Bar() {}

//// 3) Type requirements
template <typename T>
  requires requires {
    typename T::size_type;
  }
void Baz(T) {}

////////////////////////////////////////////////////////////////////////////////

int main() {
  Foo<int, 8>();            // OK
  Bar<int, 8>();            // CE
  Baz(std::vector<int>{});  // OK
}
