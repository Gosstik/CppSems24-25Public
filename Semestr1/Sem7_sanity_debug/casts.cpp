#include <iostream>

int main() {
  {
    int i = 0;
    double d = i; // OK
    double sd = static_cast<double>(i); // OK
  }

  {
    double d = 0.0;
    int i = d; // Narrowing conversion from 'double' to 'int'
    int si = static_cast<int>(d); // OK
  }

  {
    // reinterpret_cast
    long long x = 1729;
    std::cout << reinterpret_cast<double&>(x) << '\n'; // UB
  }
}
