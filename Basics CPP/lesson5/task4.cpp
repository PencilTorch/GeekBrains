//task 4
#include <iostream>
using namespace std;

const int SIZE = 5;

void printArr(int* arr, const int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void shiftArr(int* arr, int n) {
    if(n > 0){
         for(int i = 0; i < n; i++){
                 int temp = arr[0];
                 for(int j = 0; j < SIZE-1; j++){
                        arr[j] = arr[j+1];
                 }
                 arr[SIZE-1] = temp;
         }
    }
    else if(n < 0){
         for(int i = 0; i > n; i--){
                 int temp = arr[SIZE-1];
                 for(int j = SIZE-1; j > 0; j--){
                        arr[j] = arr[j-1];
                 }
                 arr[0] = temp;
         }
    }
}

int main()
{
    int arr[SIZE] = {1, 2, 3, 4, 5};
    printArr(arr, SIZE);
    int shi;
    cin>>shi;
    shiftArr(arr, shi);
    printArr(arr, SIZE);
    
    system("pause");
    return 0;
}

