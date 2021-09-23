//task 2
#include <iostream>
using namespace std;

void changer(int* arr, const int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = arr[i] == 0 ? 1 : 0;
    }
}

void printArr(int* arr, const int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    const int SIZE = 10;
    int arr[]={ 1, 1, 0, 0, 1, 0, 0, 1, 1, 0 };
    printArr(arr, SIZE);
    changer(arr, SIZE);
    printArr(arr, SIZE);
    
    system("pause");
    return 0;
}

