#include "mylib.h"

int main() {
	const int SIZE = 10;
	float* arr = new float[SIZE];
	mylib::fillArr(arr, SIZE);
	mylib::printArr(arr, SIZE);
	mylib::countPlusMinus(arr, SIZE);
	delete[] arr;
	return 0;
}