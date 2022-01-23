#include "ArrayInt.h"

int main() {
	ArrayInt arr;
	arr.push_back(11);
	arr.push_back(15);
	arr.push_back(2);
	arr.push_back(51);
	arr.push_back(10);
	arr.push_back(12);
	arr.push_back(48);
	arr.push_back(3);
	arr.printArray();

	arr.pop_back();
	arr.pop_front();
	arr.printArray();
	arr.sortArray();
	arr.printArray();
	arr.erase();
	arr.printArray();

	return 0;
}