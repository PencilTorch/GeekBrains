//task 2
#include <iostream>
using namespace std;

void changer(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == 0)
            arr[i] = 1;
        else
            arr[i] = 0;
    }
}

void printArr(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[]{ 1, 1, 0, 0, 1, 0, 0, 1, 1, 0 };
    printArr(arr, 10);
    changer(arr, 10);
    printArr(arr, 10);

    return 0;
}

