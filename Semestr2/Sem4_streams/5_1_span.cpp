#include <span>
#include <iostream>

// Why to use:
// https://stackoverflow.com/questions/45723819/what-is-a-span-and-when-should-i-use-one

// mdspan
// https://en.cppreference.com/w/cpp/container/mdspan

//// Cast will not work
// template <typename T>
// void ReverseData(std::span<T> sp) {
//   std::swap(sp.front(), sp.back());
// }

void ReverseData(std::span<int> sp) {
  std::cout << sp.size() << '\n';
  std::swap(sp.front(), sp.back());
}

void ReverseData(std::span<char> sp) {
  std::swap(sp.front(), sp.back());
}

void ReverseData(std::span<const char> sp) {
  std::cout << "sp<const char>[0] = " << sp[0] << '\n';
}

int main() {
  int arr[3] = {1, 2, 3};
  ReverseData(arr); // CE
  for (size_t i = 0; i < 3; ++i) {
    std::cout << arr[i] << ' ';
  }
  std::cout << '\n';

  ReverseData("abc"); // calls <const char> version, simple <char> gives CE
}
