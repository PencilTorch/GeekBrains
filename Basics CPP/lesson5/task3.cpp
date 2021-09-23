//task 3
#include <iostream>
using namespace std;

void printArr(int* arr, const int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void fillArr(int* arr, const int size) {
    for (int i = 0, k = 1; i < size; i++, k += 3) {
        arr[i] = k;
    }
}

int main()
{
    const int SIZE = 8;
    int arr[SIZE] = {0};
    printArr(arr, SIZE);
    fillArr(arr, SIZE);
    printArr(arr, SIZE);
    
    system("pause");
    return 0;
}

