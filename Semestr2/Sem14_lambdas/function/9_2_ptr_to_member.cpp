#include <functional>
#include <iostream>

struct Residue {
  int mod = 7;
  int Get(int val) const {
    return val % mod;
  }
  int GetNonConst(int val) {
    return val % mod;
  }
};

int main() {
  Residue r;

  //// True type
  int (Residue::*fp)(int) const = &Residue::Get;  // OK
  std::cout << (r.*fp)(8) << '\n';

  //// std::function
  // std::function<int(int)> f = &Residue::Get;           // CE
  std::function<int(Residue&, int)> f = &Residue::Get;  // OK, may omit &
  std::cout << f(r, 9) << '\n';

  //// fields
  std::function<int(Residue&)> fmod = &Residue::mod;
  std::cout << fmod(r) << '\n';

  //// GetNonConst
  // std::function<int(const Residue&, int)> fc = &Residue::GetNonConst; // CE

  //// Implicit conversions
  // int (Residue::*fp2)(long long) const = &Residue::Get;  // ! CE
  // std::function<int(Residue&, long long)> fl = &Residue::Get;  // ! OK
}
