#include <algorithm>
#include <cstring>
#include <iostream>

// Rule Of Three --- rule of thumb, not a standard term

// Ctor
// Copy ctor
// Dtor
// operator=()
// copy-and-swap idiom: 1. no code duplication 2. strong exception guaranty
// const and nonconst methods (size, capacity, ...)
// operator[]: const and non-const methods
// = default(), = delete()

// Copy elision, RVO and NRVO ???

class String {
 public:
  // Explicitly declared, implicitly defined
  // String() = default;

  String() : String(static_cast<size_t>(0)) {}

  String(size_t n, char c) : String(n) {
    // memset(data_, c, n);
    std::fill(data_, data_ + size_, c);
  }

  String(const String& other) : String(other.size_) {
    // this->String(other.sz_); // no, god, please, noooo !!!
    // memcpy(arr_, other.arr_, sz_);
    std::copy(other.data_, other.data_ + other.size_, data_);
  }

  String& operator=(const String& other) {
    if (this == &other) {
      return *this;
    }
    // this->~String(); // WRONG!!! dtor must be called once in program
    delete[] data_;
    data_ = new char[other.size_ + 1]{};
    std::copy(other.data_, other.data_ + size_, data_);
    size_ = other.size_;
    cap_ = other.cap_;

    return *this;
  }

  // // Copy And Swap (exception safe)
  // String& operator=(const String& other) {
  //   if (this == &other) {
  //     return *this;
  //   }
  //   String copy = other;  // 'other' can be passed by value
  //   Swap(copy);
  //   return *this;
  // }

  void Swap(String& other) {
    std::swap(data_, other.data_);
    std::swap(size_, other.size_);
    std::swap(cap_, other.cap_);
  }

  // BETTER USE std::cin.peek()
  // friend std::istream& operator>>(std::istream& istream, String& str) {
  //   char c = '\0';
  //   while (!(istream >> c)) {
  //     if (std::isspace(static_cast<unsigned char>(c)) != 0) {
  //       break;
  //     }
  //     // write to data
  //   }

  //   return istream;
  // }

  char& operator[](size_t index) { return data_[index]; }

  const char& operator[](size_t index) const { return data_[index]; }

  ~String() { delete[] data_; }

 private:
  explicit String(size_t size)
      : data_(new char[size + 1]{}),
        size_(size),
        cap_(size) {}

  char* data_ = nullptr;
  size_t size_ = 0;
  size_t cap_ = 0;
};

int main() {
  String s = s;  // call copy ctor
}
