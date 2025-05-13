#include <cctype>  // isdigit, isspace
#include <iostream>
#include <sstream>
#include <format>

////////////////////////////////////////////////////////////////////////////////

// Util

bool IsSign(char c) {
  return c == '+' || c == '-';
}

bool IsDigit(char c) {
  return isdigit(c) != 0;
}

class BigInt {
 public:
  BigInt() = default;
  BigInt(const char*) {}  // NOLINT
};

////////////////////////////////////////////////////////////////////////////////

// Impl

std::istream& operator>>(std::istream& is, BigInt& val) {
  std::string str;
  char ch{};

  // read sign and first digit, discarding other characters
  while (is.get(ch)) {
    if (IsSign(ch)) {
      char digit{};
      if (!is.get(digit)) {
        return is;
      }
      if (!IsDigit(digit)) {
        is.unget();
        continue;
      }
      str.push_back(ch);
      str.push_back(digit);
      break;
    }
    if (IsDigit(ch)) {
      str.push_back(ch);
      break;
    }
  }

  // unable to read at least one digit, return without modifying val
  if (!is) {
    return is;
  }

  // read remaining digits
  while (is.get(ch)) {
    if (!IsDigit(ch)) {
      is.unget();
      break;
    }
    str.push_back(ch);
  }
  std::cout << "'" << str << "'";  // to test
  val = BigInt(str.c_str());

  return is;
}

////////////////////////////////////////////////////////////////////////////////

// Test

void Test(std::string input, std::string expected) {
  BigInt val;
  std::stringstream ss(input);
  std::cout << std::format("Expected:\t'{}'\n", expected);
  std::cout << "Actual:\t\t";
  ss >> val;
  std::cout << "\n-----------------\n";
}

int main() {
  Test("0", "0");
  Test("+0", "+0");
  Test("-0", "-0");
  Test("+234", "+234");
  Test("-234", "-234");
  Test("234", "234");
  Test("23 4", "23");
  Test("- 23 4", "23");
  Test(" \t\n 23 4", "23");
  Test("+ 23 4", "23");
  Test(" +-\t\n 23 4   ", "23");
  Test("qwer+edf-wekg+45ferg", "+45");
}
