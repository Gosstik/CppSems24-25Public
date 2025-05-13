#include <set>

int main() {
  int c = 1;
  auto cmp = [](int a, int b) {
    return a < b;
  };
  auto ref_cmp = [&](int a, int b) mutable {
    return a + c < b;
  };
  auto val_cmp = [=](int a, int b) {
    return a + c < b;
  };

  // All have copy (and move) ctor
  auto cmp_copy = cmp;      // OK
  auto ref_copy = ref_cmp;  // OK
  auto val_copy = val_cmp;  // OK

  // No operator=() when capture
  cmp = cmp_copy;      // OK
  ref_cmp = ref_copy;  // ! CE
  ref_cmp = ref_copy;  // ! CE

  // Works !!!
  std::set<int, decltype(cmp)> s(cmp);           // OK
  std::set<int, decltype(ref_cmp)> sr(ref_cmp);  // OK
  std::set<int, decltype(val_cmp)> sv(val_cmp);  // OK

  // No default ctor when capture
  std::set<int, decltype(cmp)> sd;       // OK
  std::set<int, decltype(ref_cmp)> srd;  // ! CE
  std::set<int, decltype(val_cmp)> svd;  // ! CE
}
