#include <iostream>
using namespace std;

#define ARRAY_SIZE 5
#define SwapINT(a, b) if(a > b)temp=a;a=b;b=temp;

void printArr(int* arr, int size);

int main() {
int* arr = new int[ARRAY_SIZE];
for (size_t i = 0; i < ARRAY_SIZE; i++) {
	cout << "arr[" << i << "] = ";
	cin >> arr[i];
}
int temp;
for (int i = 0; i < ARRAY_SIZE - 1; i++) {
	for (int j = 0; j < ARRAY_SIZE - i - 1; j++) {
		if (arr[j] > arr[j + 1]) {
			temp = arr[j];
			arr[j] = arr[j + 1];
			arr[j + 1] = temp;
		}
	}
}
printArr(arr, ARRAY_SIZE);

delete[] arr;
return 0;
}

void printArr(int* arr, int size) {
	for (size_t i = 0; i < ARRAY_SIZE; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}