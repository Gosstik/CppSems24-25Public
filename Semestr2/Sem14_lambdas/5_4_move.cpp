#include <utility>

int main() {
  int c = 1;
  auto ref_cmp = [&](int a, int b) mutable {
    return a + c < b;
  };

  auto ref_copy = ref_cmp;
  auto ref_move = std::move(ref_cmp); // copy ctor
}
