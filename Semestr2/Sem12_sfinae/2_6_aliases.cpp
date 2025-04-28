#include <vector>
#include <type_traits>

// Aliases does not comply to common rules of template substitution.
// Actually, alias does not define template id.
// !!! Therefore, we cannot specialize aliases.
// !!! CTAD also does not work

template <typename T>
using Vec = std::vector<T>;

int main() {
  std::vector v1 = {1, 2, 3, 4}; // OK, CTAD
  // !!! no CTAD: argument deduction only allowed for class templates
  Vec v2 = {1, 2, 3, 4};
}
