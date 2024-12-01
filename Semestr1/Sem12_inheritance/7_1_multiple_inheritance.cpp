#include <iostream>

// TODO

// memory layout

struct Granny {};
struct Mom: Granny {};
struct Dad: Granny {};

struct Son: Mom, Dad {};

int main() {

}
