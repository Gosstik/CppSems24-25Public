#include <cstring>  // TODO: add examples

#include <algorithm>
#include <iostream>
#include <vector>

bool LexicalStringsCmp(const char* lhs, const char* rhs) {
  return strcmp(lhs, rhs) < 0;
}

void Snippets() {
  {
    // C style strings: usage

    char str_arr[] = "abcde";
    std::cout << str_arr << '\n';

    const char* str = "aaa";
    std::cout << str_arr << '\n';

    // ??? str = "Hello, world!"
    // What type does "Hello, world!" has? --- const char[14]
  }

  {
    // Null terminator (C style strings == Null-terminated strings)

    char str_arr1[] = "abcde"; // copy of "abcde" to str_arr
    char str_arr2[] = {'a', 'b', 'c', 'd', 'e'};
    std::cout << sizeof(str_arr1) << ' ' << sizeof(str_arr2) << '\n'; // ???

    const char* str = "aaa";  // array to pointer conversion
    std::cout << sizeof(str) << '\n'; // ???

    char* str2 = "bbb"; // NOT OK, violation of ISO C++11

    char zero_str[] = "abc\0def";
    std::cout << zero_str << ' ' << sizeof(zero_str) << '\n'; // ???
  }

  {
    // Escape sequences
    const char* s1 = "1:\ttext";
    const char* s10 = "10:\ttext";
    const char* s100 = "100:\ttext";

    std::cout << s1 << '\n';
    std::cout << s10 << '\n';
    std::cout << s100 << '\n';
  }

  // clang-format off
  {
    // Concatenation and indexing

    const char* str = "first, " "second, " "third, " "...";
    std::cout << str << '\n';

    str = "first, " "second, "
        "third, ""...";
    std::cout << str << '\n';

    size_t i = 3;
    std::cout << "Indexed string"[i] << '\n';
  }
  // clang-format on

  {
    // Raw strings
    std::cout << "print linefeed: \"\\n\"" << '\n';  // Difficult to read
    std::cout << R"(print linefeed: "\n")" << '\n';  // More elegant solution

    std::cout << '\n';

    // Multiline strings
    const char* multi_raw_str = R"(Multi
line
string)";

    std::cout << multi_raw_str << '\n';
  }

  {
    // strlen

    char str[] = "Hello, world!\n";
    size_t len = strlen(str);
    for (size_t i = 0; i < len; ++i) {
      std::cout << str[i];
    }
    std::cout << '\n';

    // Difference sizeof() and strlen(): O(1) and O(len)
    // sizeof() --- compile time concept, it is REPLACED WITH VALUES in asm
    // strlen() --- runtime concept, it is evaluated in cycle
    const char* s = "abc\0def";
    std::cout << strlen(s) << ' ' << sizeof(s) << '\n'; // ???
  }

  {
    // strcpy

    const char* src = "Some short string";
    // ...
    char buf[100]{};
    strcpy(buf, src);
    size_t len = strlen(buf);
    for (size_t i = 0; i < len; ++i) {
      std::cout << buf[i];
    }
    std::cout << '\n';
  }

  {
    // strcmp: https://en.cppreference.com/w/cpp/string/byte/strcmp

    // lexicographical comparison
    std::vector<const char*> strs{"aab", "bc", "abc", "a", "ca", "bb", "bbc"};
    std::sort(strs.begin(), strs.end(), LexicalStringsCmp);

    for (const char* str : strs) {
      std::cout << str << '\n';
    }
  }

  {
    // atoi // alphabetical to int: https://en.cppreference.com/w/cpp/string/byte/atoi
    // atof // alphabetical to float
    // strtol // More convenient and allows to parse different base

    char str_int[] = "   123+456";
    int a = atoi(str_int);
    std::cout << "a = " << a << '\n'; // 123

    char str_float[] = "243.4e-2"; // == 2.434
    float f = atof(str_float);
    std::cout << "f = " << f << '\n';

    char** p = nullptr;
    int64_t res = strtol(str_int, p, 10);
    std::cout << str_int << ' ' << *p; // out: 123 +456
  }

  {
    // memcpy, memmove

    int a1[5] = {1, 2, 3};
    int a2[3] = {5, 6};
    size_t a1_len = sizeof(a1) / sizeof(int);
    size_t a2_len = sizeof(a2) / sizeof(int);

    void* v = a1;
    memcpy(a1, a2, std::min(sizeof(a1), sizeof(a2))); // OK
    // memcpy(a1, a1 + 1, (a1_len - 1) * sizeof(int)); // UB
    // memmove(a1, a1 + 1, (a1_len - 1) * sizeof(int)); // OK
    // std::copy(a1, a1 + a1_len - 1, a1 + 1); // UB
    // std::copy_backward(a1, a1 + a1_len - 1, a1 + 1); // OK

    for (size_t i = 0; i < a1_len; ++i) {
      std::cout << a1[i] << ' ';
    }

    std::cout << '\n';

    for (size_t i = 0; i < a2_len; ++i) {
      std::cout << a2[i] << ' ';
    }

    // memcpy vs strcpy: "abc\0cde"
  }

  {
    // std::copy and std::copy_backward
    std::vector<size_t> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    auto b = vec.begin();
    auto e = vec.end();

    // can't use memcpy and memmove

    std::copy(b, b + 5, b + 5); // OK
    // std::copy(b, b + 5, b + 1); // UB
    // std::copy_backward(b, b + 5, b + 6); // OK, same as above
    // std::copy_backward(b + 5, b + 10, b + 6); // UB

    for (auto elem: vec) {
      std::cout << elem << ' ';
    }
    std::cout << '\n';
  }
}

int main() { Snippets(); }
