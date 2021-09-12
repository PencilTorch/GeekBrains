//task 3
#include <iostream>
using namespace std;

void printArr(int* arr, int size = 8) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void filler(int* arr, int size = 8) {
    for (int i = 0, k = 1; i < 0; i++, k += 3) {
        arr[i] = k;
    }
}

int main()
{
    int arr[8];
    printArr(arr);
    filler(arr);
    printArr(arr);

    return 0;
}

