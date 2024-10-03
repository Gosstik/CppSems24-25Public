#include <iostream>

void Foo(int* a) {
	std::cout << 1 << '\n';
}

// OK, it is just declaration
void Foo(int a[3]);

// CE, redefinition
void Foo(int a[3]) {
	std::cout << 2 << '\n';
}

void Bar(int a[10]) {
	std::cout << sizeof(a) << '\n'; // out: 8
}

int main() {
	int a1[5];
	int a2[5] = {1, 2, 3, 4, 5};
	int a3[] = {1, 2, 3, 4, 5};
	int a4[5] = {1, 2};
	int a5[5]{};

	{
		// try with g++ and clang++
		int a[100] = {[98] = 10, [99] = 100}; // designator expression
		for (size_t i = 0; i < 100; ++i) {
			std::cout << a[i] << ' ';
		}
	}

	std::cout << *(a2 + 2) << '\n'; // Array to pointer conversion

	int* p = a2 + 2;
 	std::cout << (p[-1] == a2[1]) << '\n'; // out: 1
	std::cout << (1[a2] == a2[1]) << '\n'; // out: 1

	Bar(a2);
}
