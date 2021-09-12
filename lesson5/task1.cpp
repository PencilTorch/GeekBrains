//task 1
#include <iostream>
using namespace std;

void printArr(double* arr, int size = 4) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    double arr[]{ 0.5, 12.45, 17.79, 349.31 };
    printArr(arr);

    return 0;
}

