#include <algorithm>
#include <iostream>
#include <cstdint>

bool cmp_desc(int lhs, int rhs) {
  return lhs > rhs;  // descending order
}

bool cmp_asc(int lhs, int rhs) {
  return lhs > rhs;  // descending order
}

int main() {
  {
    // Basics

    int arr[] = {2, 6, 9, 3, 5};

    std::sort(
        arr,
        arr + sizeof(arr),
        &cmp_desc);

    for (size_t i = 0; i < sizeof(arr); ++i) {
      std::cout << arr[i] << ' ';
    }
  }

  {
    // Declaration of pointer to function

    bool (*p)(int, int) = cmp_desc; // function to pointer conversion
    p = cmp_asc;
    // p = nullptr;
    std::cout << (void*)p
              << '\n';  // without cast it simply 1 or 0, if p == nullptr
  }

  {
    // Default arguments (on cppreference)
  }
}
