#include <iostream>
#include <string>
#include <type_traits>
#include <variant>
#include <vector>

// Overload pattern

template <typename... Ts>
struct Overload : Ts... {
  using Ts::operator()...;  // since c++17
};

template <class... Ts>
Overload(Ts...) -> Overload<Ts...>;

int main() {
  std::vector<std::variant<std::vector<int>, double, std::string>> vecVariant =
      {
          1.5,
          std::vector<int>{1, 2, 3, 4, 5},
          "Hello",
      };

  auto DisplayMe = Overload{
      [](std::vector<int>& vec) {
        for (auto v : vec) {
          std::cout << v << " ";
        }
        std::cout << '\n';
      },
      [](auto& arg) {
        if constexpr (std::
                          is_same_v<std::decay_t<decltype(arg)>, std::string>) {
          std::cout << "string: " << arg << '\n';
        } else {
          std::cout << "other\n";
        }
      }
  };

  for (auto& v : vecVariant) {
    std::visit(DisplayMe, v);
  }
}
