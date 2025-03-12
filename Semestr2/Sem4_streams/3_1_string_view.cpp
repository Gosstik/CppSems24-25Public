#include <iostream>
#include <string>
#include <string_view>

// since c++17

// Motivation: avoid unecessary allocations
// https://en.cppreference.com/w/cpp/string/basic_string_view

static constexpr std::string_view kTableName =
    "order_details";  // OK, without allocation
// static constexpr std::string kTableName = "order_details"; // OK

void Printer(const std::string& s) {
  std::cout << "Printer: " << s << '\n';
}

// !!! Do not use references for views
std::string_view GetWordInSquareBrackets(std::string_view sv) {
  sv.remove_prefix(sv.find('[') + 1);          // No allocation
  sv.remove_suffix(sv.size() - sv.find(']'));  // No allocation
  // Printer(sv); // CE
  // Printer(sv.data()); // ???
  return sv;
}

int main() {
  std::string s("We have to parse [word] in square brackets");
  std::string_view sv("We have to parse [word] in square brackets");  // OK
  // // ...
  std::string a = sv;  // CE, ctor std::string(std::string_view) is explicit
  std::string b(sv);   // OK

  std::cout << kTableName << '\n';

  // std::string_view word = GetWordInSquareBrackets(s);
  std::string_view word =
      GetWordInSquareBrackets("We have to parse [word] in square brackets");
  std::cout << word << '\n';
}
