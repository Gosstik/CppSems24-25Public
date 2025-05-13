#include <iostream>
#include <vector>


int main() {
	//// RE (not UB)
	{
		std::vector<int> v(10);
		std::cout << v[1'000'000] << '\n'; // RE, Segmentation Fault
	}

	{
		int x = 1;
		std::cin >> x; // suppress compiler warnings
		std::cout << 10.0 / x << '\n'; // RE, Floating Point Exception
	}


	{
		std::vector<int> v(1);
		std::cout << v.at(2) << '\n'; // RE, Aborted
	}

	{
		std::vector<int> v(1);
		v[-1] = 1; // RE, Aborted: Double free or corruption
	}
}
