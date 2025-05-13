#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

#include <boost/bind.hpp>

struct Person {
  std::string Name() const {
    return name;
  }

  std::string name;
};

int main() {
  std::vector<Person> vec{
    Person{"Mike"},
    Person{"Nick"},
    Person{"Ann"},
    Person{"Maggy"},
  };
  std::sort(vec.begin(), vec.end(), boost::bind(&Person::Name, _1) < boost::bind(&Person::Name, _2));
  // std::cout << "CHANGED\n";

  for (auto& p: vec) {
    std::cout << p.name << std::endl;
  }
}
