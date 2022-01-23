#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

int count_of_unique(std::vector<int>& vec) {
	int count = 0;
	for (auto value : vec)
		if (std::count_if(vec.cbegin(), vec.cend(), [value](const int& x) {return x == value; }) == 1)
			count++;
	return count;
}

int main() {
	srand(time(NULL));
	std::vector<int> v;
	v.resize(15);
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
		*(it) = rand() % 10;
	}

	for (auto it : v) {
		std::cout << it <<" ";
	}
	std::cout << "\nCount of unique elements: ";
	std::cout << count_of_unique(v);

	return 0;
}