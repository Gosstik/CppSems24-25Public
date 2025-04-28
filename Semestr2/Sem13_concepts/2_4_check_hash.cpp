#include <unordered_map>

template <typename T>
  requires requires(T a) {
    typename std::hash<T>;  // always true because hash is a template
    std::hash<T>()(a);
  }
void Test() {}

int main() {
  Test<int>();   // OK
  Test<void>();  // CE
}
