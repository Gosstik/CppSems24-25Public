#include <algorithm>
#include <iostream>
#include <string>
#include <string_view>
#include <unordered_map>
#include <vector>

// sso
// invalid use of push_back with views

struct Item {
  std::string name;
};

class Storage {
 public:
  size_t Add(Item&& item) {
    size_t id = by_id_.size();
    by_id_.emplace_back(std::move(item));
    by_name_.emplace(by_id_.back().name, id);
    return id;
  }

  Item* get_by_id(size_t id) {
    return id < by_id_.size() ? &by_id_[id] : nullptr;
  }

  Item* get_by_name(const std::string_view& name) {
    return by_name_.contains(name) ? get_by_id(by_name_.at(name)) : nullptr;
  }

  template <class F>
  void for_each(F&& f) {
    std::for_each(by_id_.begin(), by_id_.end(), f);
  }

 private:
  std::vector<Item> by_id_;
  std::unordered_map<std::string_view, size_t> by_name_;
};

int main() {
  Storage s;
  s.Add(Item("abc"));
  s.Add(Item("cde"));
  s.Add(Item("def"));

  s.for_each([](auto&& item) {
    std::cout << item.name << '\n';
  });

  auto item = s.get_by_name("abc");
  std::cout << item->name << '\n';
}
