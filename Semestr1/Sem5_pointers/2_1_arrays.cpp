#include <iostream>

// More
// Arrays declaration: https://en.cppreference.com/w/cpp/language/array
// Arrays initialization:
// https://en.cppreference.com/w/c/language/array_initialization

////////////////////////////////////////////////////////////////////////////////

void Foo(int* a) { std::cout << 1 << '\n'; }

// OK, same as above, but it is just declaration
void Foo(int a[10]);
void Foo(int a[]);

// CE, redefinition
void Foo(int a[3]) { std::cout << 2 << '\n'; }

// Sizeof array as argument
void Bar(int a[10]) {
  std::cout << sizeof(a) << '\n';  // ???
}

void Baz(int* a, size_t a_size) {
  // The only way to get size of array is to force user to pass it as argument
  for (size_t i = 0; i < a_size; ++i) {
    std::cout << a[i] << ' ';
  }
  std::cout << '\n';
}

////////////////////////////////////////////////////////////////////////////////

void Snippets() {
  {
    // Array declaration

    int a1[5];
    int a2[5] = {1, 2, 3, 4, 5};
    int a3[] = {1, 2, 3, 4, 5};
    int a4[5] = {1, 2};
    int a5[5]{};
  }

  {
    // designator expression (try with g++ and clang++)

    int a[100] = {[98] = 10, [99] = 100};
    for (size_t i = 0; i < 100; ++i) {
      std::cout << a[i] << ' ';
    }
  }

  {
    // Indexing

    int arr[5] = {1, 2, 3, 4, 5};
    std::cout << *(arr + 2) << '\n';  // Array to pointer conversion (implicit)

    int* p2 = arr + 2;  // Array to pointer conversion

    // ptr[ind] == *(ptr + ind)
    std::cout << (p2[-1] == arr[1]) << '\n';   // negative ind
    std::cout << (1 [arr] == arr[1]) << '\n';  // swap arr and ind

    Bar(arr);
  }

  {
    // Difference between array and pointer

    int a1[3] = {1, 2, 3};
    int a2[3] = {4, 5, 6};

    int* p1 = a1;
    int* p2 = a2;

    // Assignment
    a1 = a2;  // CE
    p1 = p2;  // OK

    // Addition
    a1 += 2;  // CE
    p1 += 2;  // OK

    // sizeof
    p1 = a1;
    std::cout << sizeof(a1) << ' ' << sizeof(p1) << '\n';  // ???

    // Conversion when passed to function
    // See Foo declarations above
    Foo(a1);
    Bar(a2);
  }

  {
    // VLA - Variable Length Array (DO NOT USE IT !!!)
    // OK in C

    size_t n = 5;
    int a[n];
    for (size_t i = 0; i < sizeof(n); ++i) {
      a[i] = i;
    }
    for (size_t i = 0; i < sizeof(n); ++i) {
      std::cout << a[i];
    }
  }

  {
    // int arr[10'000'000]{}; // UB (likely segmentation fault)
    static int sarr[10'000'000]{};  // OK, in static memory
    std::cout << sarr[0] << '\n';
  }
}

int main() { Snippets(); }
