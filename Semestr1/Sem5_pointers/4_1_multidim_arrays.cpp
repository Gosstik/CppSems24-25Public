#include <iostream>
#include <vector>

// Explanation: Cases 1 and 2 perform array to pointer conversion.
// Case 3 cannot perform that conversion, because outer type is pointer

void Foo(int** a) {
  std::cout << 1 << '\n';
}

void Foo(int* a[5]) {
  std::cout << 2 << '\n';
}

// different (but also point to the first element)
void Foo(int (*a)[5]) {
  std::cout << 3 << '\n';
}

////////////////////////////////////////////////////////////////////////////////

void Bar(int a[][5], size_t height) {
  // a[i][j] == *(a + i * 5 + j)
  std::cout << "Print matrix:\n";
  for (size_t i = 0; i < height; ++i) {
    for (size_t j = 0; j < 5; ++j) {
      std::cout << a[i][j] << ' ';
    }
    std::cout << '\n';
  }
  std::cout << '\n';
}

void Snippets() {
  {
    // int**
    int a = 0;
    int* p = &a;
    std::cout << p << '\n';  // address

    int** pp = &p;
    std::cout << pp << '\n';  // also address
    std::cout << (*pp == p) << (**pp == a) << '\n';
  }

  {
    int one_dim[5] = {1, 2, 3, 4, 5};
    int* p_one = one_dim;  // array to pointer conversion

    int a[5][5] = {};
    Bar(a, 5);

    // Same as ++a++ == ++(a++)
    int* b[5];   // Array of 5 pointers to int
    int(*c)[5];  // Pointer to array of 5 ints

    std::cout << sizeof(b) << ' ' << sizeof(c) << '\n';

    int** ppa = a;    // CE
    int* pa[5] = a;   // CE
    int(*ap)[5] = a;  // OK, array to pointer conversion

    int** ppb = b;  // OK, array to pointer conversion
    int** ppc = c;  // CE

    Foo(a);  // OK, but what version?
  }

  {
    // difference between int[][] and int**
    int** dim2arr = new int*[7];
    for (size_t i = 0; i < 7; ++i) {
      dim2arr[i] = new int[i + 1];
    }

    for (size_t i = 0; i < 7; ++i) {
      delete[] dim2arr[i];
    }
    delete[] dim2arr;

    //! 1 dereference vs 2
    // a[i][j] == *(a + i * 5 + j)
    // dim2arr[i][j] = *(*(dim2arr + i) + j);
  }

  {
    // 2 dim vector
    std::vector<std::vector<int>> vv({{1, 2, 3}, {4, 5}});
  }
}

int main() {
  Snippets();
}
