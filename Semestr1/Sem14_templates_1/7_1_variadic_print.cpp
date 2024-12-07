#include <iostream>

void Print() {
  std::cout << '\n';
}

template <typename Head, typename... Args>
void Print(Head head, Args... args) {
  std::cout << head << ' ';
  Print(args...);
}

int main() {
  Print(1, 2.9, 'c', "abcd");
}
