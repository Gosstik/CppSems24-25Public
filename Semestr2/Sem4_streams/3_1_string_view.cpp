#include <iostream>
#include <string>
#include <string_view>

// since c++17

// Motivation: avoid unecessary allocations
// https://en.cppreference.com/w/cpp/string/basic_string_view

static constexpr std::string_view kTableName = "order_details";

// Do not use references !!!
std::string_view GetWordInSquareBrackets(std::string_view sv) {
  sv.remove_prefix(sv.find('[') + 1);          // No allocation
  sv.remove_suffix(sv.size() - sv.find(']'));  // No allocation
  return sv;
}

int main() {
  std::string s("We have to parse [word] in square brackets");
  // ...
  std::string_view word = GetWordInSquareBrackets(s);
  std::cout << word << '\n';
}
