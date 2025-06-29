#include <iostream>
#include <vector>


int main() {
	//// RE
	{
		std::vector<int> v(10);
		std::cout << v[1'000'000] << '\n'; // UB, but in most cases RE (Segmentation Fault)
	}

	{
		int x = 1;
		std::cin >> x; // suppress compiler warnings
		std::cout << 10.0 / x << '\n'; // RE, Floating Point Exception (x=0)
	}

	{
		std::vector<int> v(1);
		std::cout << v.at(2) << '\n'; // RE, Aborted
	}

	{
		std::vector<int> v(1);
		v[-1] = 1; // UB, but in most cases RE (Aborted: Double free or corruption)
	}
}
