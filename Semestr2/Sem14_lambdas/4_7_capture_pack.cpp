#include <iostream>
#include <string>

template <typename... Strs>
  requires((std::is_same_v<Strs, std::string> && ...))
void Test(const Strs&... strs) {
  auto contains_strs = [&strs...](const std::string& str) {
    return ((str.find(strs) != std::string::npos) && ...);
  };

  // auto contains_strs2 = [...strs = strs](const std::string& str) {
  //   return ((str.find(strs) != std::string::npos) && ...);
  // };

  std::cout << contains_strs("abcde") << '\n';
  std::cout << contains_strs("h") << '\n';
}

// pack with init
template <typename... Strs>
  requires((std::is_same_v<Strs, std::string> && ...)) // require rvalue
void TestInit(Strs&&... strs) {
  // !!! different order of ... for capture with initialization
  auto contains_strs = [...strs = std::move(strs)](const std::string& str) {
    return ((str.find(strs) != std::string::npos) && ...);
  };

  std::cout << contains_strs("abcde") << '\n';
  std::cout << contains_strs("h") << '\n';
}

int main() {
  std::string s1("abc");
  std::string s2("cde");
  Test(s1, s2);

  TestInit(std::move(s1), std::move(s2));
}
