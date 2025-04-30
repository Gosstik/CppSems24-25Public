#include <unordered_map>

template <typename T>
  requires requires() {
    typename std::hash<T>;  // always true because hash is a template (it is not
                            // instantiated)
    std::hash<T>()(std::declval<T>()); // 
  }
void Test() {}

int main() {
  Test<int>();   // OK
  Test<void>();  // CE
}
