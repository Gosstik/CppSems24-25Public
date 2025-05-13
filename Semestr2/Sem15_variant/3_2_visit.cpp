#include <iostream>
#include <string>
#include <variant>

// why constexpr works ???

void OneVariant() {
  std::variant<int, std::string> v = 1;

  v = 1;
  // v = "abc";

  std::visit(
      [](const auto& item) {
        if constexpr (std::is_same_v<decltype(item), const int&>) {
          std::cout << "int\n";
        } else {
          std::cout << "not int\n";
        }
      },
      v
  );
}

void TwoVariants() {
  std::variant<int, std::string> v1 = 1;
  std::variant<int, std::string> v2 = "abc";
  // std::variant<int, std::string> v2 = 2;

  std::visit(
      [](const auto& item1, const auto& item2) {
        if constexpr (std::is_same_v<decltype(item1), decltype(item2)>) {
          std::cout << "same\n";
        } else {
          std::cout << "not same\n";
        }
      },
      v1,
      v2
  );
}

int main() {
  OneVariant();
  // TwoVariants();
}
