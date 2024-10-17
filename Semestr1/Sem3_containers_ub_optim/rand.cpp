#include <iostream>
#include <vector>
#include <random>


using ValueType = int64_t;
// typedef int64_t ValueType; // Not recommended

struct PartitionBounds {
  size_t equal;    // iter with elems: pivot <= val
  size_t greater;  // iter with elems: pivot < val
};

bool LessFunc(ValueType left, ValueType right) {
  return left < right;
}

PartitionBounds Partition(std::vector<ValueType>& vec, size_t first,
                          size_t last, ValueType pivot,
                          bool (*cmp)(ValueType, ValueType)) {
  // One or zero elements.
  if (last - first < 2) {
    return {first, last};
  }

  // General case.
  PartitionBounds res{first, last};
  size_t cur = first;
  while (vec[cur] < vec[res.greater]) {  // [<pivot, =pivot, >pivot]
    // elements with index in [first, res.equal) are smaller to pivot.
    // elements with index in [res.equal, cur) are equal to pivot.
    // elements with index in [cur, res.greater] are not examined yet.
    // elements with index in (res.greater, last) are greater than pivot.

    if (cmp(vec[cur], pivot)) {
      // vec[cur] < pivot
      std::swap(vec[res.equal], vec[cur]);
      ++res.equal;
      ++cur;
    } else if (cmp(pivot, vec[cur])) {
      // vec[cur] > pivot
      --res.greater;
      std::swap(vec[res.greater], vec[cur]);
    } else {
      // vec[cur] == pivot
      ++cur;
    }
  }
  return res;
}

////////////////////////////////////////////////////////////////////////////////

void PrintParts(std::vector<ValueType>& vec, PartitionBounds& bounds) {
  std::cout << "Left part: ";
  for (size_t i = 0; i < bounds.equal; ++i) {
    std::cout << vec[i] << ' ';
  }
  std::cout << '\n';

  std::cout << "Equal part: ";
  for (size_t i = bounds.equal; i < bounds.greater; ++i) {
    std::cout << vec[i] << ' ';
  }
  std::cout << '\n';

  std::cout << "Greater part: ";
  for (size_t i = bounds.greater; i < vec.size(); ++i) {
    std::cout << vec[i] << ' ';
  }
  std::cout << '\n';
}

void VisualTest() {
  std::vector<ValueType> vec = {-11, 4, 8, -5, 0, 9, -3, 2, 5, 0, 2, -5, 0};
  PartitionBounds bounds = Partition(vec, 0, vec.size(), 0, LessFunc);
  // std::less<ValueType>{}

  PrintParts(vec, bounds);
}

void RandomPivot() {
  std::vector<ValueType> vec = {-11, 4, 8, -5, 0, 9, -3, 2, 5, 0, 2, -5, 0};

  std::random_device seeder;
  std::mt19937_64 gen(seeder());

  size_t random_i = gen() % vec.size();
  ValueType pivot = vec[random_i];
  PartitionBounds bounds = Partition(vec, 0, vec.size(), pivot, LessFunc);

  std::cout << "Random index: " << random_i << '\n';
  std::cout << "Pivot: " << pivot << '\n';
  PrintParts(vec, bounds);
}

int main() {
  VisualTest();
  // RandomPivot();
}
