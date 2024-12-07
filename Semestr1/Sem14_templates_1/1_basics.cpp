#include <iostream>

// What's wrong ??? --- Min should accept const T&

template <typename T>
void Swap(T& a, T& b) {
  T temp = a;
  a = b;
  b = temp;
}

template <typename T>
T Min(T& a, T& b) {
  return a < b ? a : b;
}
