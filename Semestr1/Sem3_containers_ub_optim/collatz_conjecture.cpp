// UB, try with -O3 in godbolt
int collatz_conjecture(int i) {
  while (i != 1) {
    if (i % 2 == 0) {
      i /= 2;
    } else {
      i = 3 * i + 1;
    }
  }

  return i;
}

int main() {
  collatz_conjecture(10);
  return 5;
}
