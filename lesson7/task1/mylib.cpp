#include "mylib.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void fillArr(float* arr, int size)
{
	srand(static_cast<unsigned int>(time(0)));
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = rand() % 200 - 100;
	}
}

void printArr(float* arr, int size)
{
	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void countPlusMinus(float* arr, int size)
{
	int countP = 0;
	int countN = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (arr[i] >= 0)
			countP += 1;
		else
			countN += 1;
	}
	cout << "Count pozitive elements: " << countP << endl;
	cout << "Count negative elements: " << countN << endl;
}
