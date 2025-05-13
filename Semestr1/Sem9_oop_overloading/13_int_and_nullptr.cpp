#include <cstdint>

struct BigInteger {
  explicit BigInteger(const char* str) {}
  BigInteger(uint64_t val) {}
};

int main() {
  BigInteger v1(0);               // CE
  BigInteger v2 = 0;              // OK with explicit, copy elision
  BigInteger v3 = BigInteger(0);  // CE
}
