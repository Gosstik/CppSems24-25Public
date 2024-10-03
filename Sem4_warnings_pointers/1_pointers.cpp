#include <iostream>
#include <vector>

int main() {
	{
		int x = 10;
		int y = 20;
		std::cout << &x << '\n';

		int* p = &x;
		std::cout << *p << '\n'; // dereference

		int *p1 = &x, *p2 = &y;
		std::cout << p1 << ' ' << p2 << '\n';
	}

	{
		std::vector<int> v = {1, 2, 3, 4, 5};
		int* p0 = &v[0];
    int* p3 = &v[3];
    std::cout << p3 - p0 << '\n'; // 3
		std::cout << *p0 << '\n'; // 1

    // Better way
    int* pv0 = v.data();
    int* pv3 = v.data() + 3;
    // ...
	}

	{
		// Dangling pointer
		int a = 1;
		int* p = &a;
		{
			int b = 2;
			p = &b;
		}
    // std::cout << b << ' '; // CE
		std::cout << p << ' '; // No UB, because no dereference
		std::cout << *p << '\n'; // UB, try O0 and O1 optimization

		int c = 3, d = 4, e = 5, f = 6;
		std::cout << &c << ' ' << &d << ' ' << &e << ' ' << &f << '\n';
		++*p; // UB
		std::cout << c << d << e << f << *p << '\n';
	}
}
