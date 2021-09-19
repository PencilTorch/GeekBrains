#include "mylib.h"

int main() {

	const int SIZE = 10;
	float arr[SIZE];
	fillArr(arr, SIZE);
	printArr(arr, SIZE);
	countPlusMinus(arr, SIZE);

	return 0;
}