#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
  std::vector<std::string> v = {"abc", "def", "ace"};
  std::string sub = "a";

  auto contains_sub = [&sub](const std::string& s) {
    return s.find(sub) != std::string::npos;
  };

  sub += 'h';

  auto it = std::find_if(v.begin(), v.end(), contains_sub);
  std::cout << (it == v.end()) << '\n';

  //////////////////////////////////////////////////////////////////////////////

  std::string sub2 = "b";
  auto diff = [sub, &sub2]() mutable {
    sub[0] = 1;
    sub2[0] = 1;
  };
}
