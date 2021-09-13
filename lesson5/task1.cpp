//task 1
#include <iostream>
using namespace std;

void printArr(double* arr, const int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    const int SIZE = 5;
    double arr[]={ 0.5, 12.45, 17.79, 349.31, 249.15 };
    printArr(arr, SIZE);
    
    system("pause");
    return 0;
}

