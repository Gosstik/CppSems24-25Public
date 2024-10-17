#include <iostream>
#include <vector>

void Swap(int* lhs, int* rhs) {
  int tmp = *lhs;
	*lhs = *rhs;
	*rhs = tmp;
}

int main() {
	{
		// Basics, how to get address of variable

    int x = 10;
		int y = 20;
		std::cout << &x << '\n';

		int* p = &x;
		std::cout << *p << '\n'; // dereference
    std::cout << *&p << ' ' << &*p << '\n'; // OK

		int *p1 = &x, *p2 = &y; // ! save * for p2
		std::cout << p1 << ' ' << p2 << '\n';
	}

  {
    // Operations
    int x = 10;
    int y = 20;
    int* px = &x;
    int* py = &y;

    px = px + 1;
    px += 1;
    ++px; // OK
    px -= 3;
    &x = 1; // CE, &x is rvalue
    int* px1 = &(x + 1); // CE

    // TODO: comparisons

    std::ptrdiff_t dist = py - px; // OK, but UB
    int* pp = px + py; // CE
  }

  {
    // void*

    // TODO

    // unable to dereference
    // any pointer can be casted to void*
  }

  {
    // nullptr

    // TODO
    // may be assigned to any pointer
    // type: std::nullptr_t
    // in C only since C23, earlier: NULL (macros)
  }

	{
		std::vector<int> v = {1, 2, 3, 4, 5};
		int* p0 = &v[0];
    int* p3 = &v[3];
    std::cout << p3 - p0 << '\n'; // 3
		std::cout << *p0 << '\n'; // 1

    // Another way
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

  {
    // Swap

    int a = 1;
    int b = 2;
    Swap(&a, &b);
    std::cout << a << ' ' << b << '\n';
  }
}
