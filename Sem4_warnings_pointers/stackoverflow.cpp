#include <iostream>

void Foo(int a) {
	std::cout << a << '\n';
	Foo(a + 1); // RE, Segmentation Fault
}

int main() {
	Foo(1);
}
