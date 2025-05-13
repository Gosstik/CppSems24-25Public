// ranges !!!

#include <ranges>
#include <vector>
#include <algorithm>

struct Point {
  int x;
  int y;
};

int main() {
  std::vector<Point> v;
  std::ranges::sort(v, {}, [](auto a){ return a.x; });
  std::ranges::sort(v, {}, &Point::x); // OK, same as above
}
