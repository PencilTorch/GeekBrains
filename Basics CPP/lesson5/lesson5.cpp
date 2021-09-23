#include <iostream>
using namespace std;
//task 1 
{
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
    
    return 0;
}

}
//task 2
{
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
    
    return 0;
}

}
//task 3
{
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
    
    return 0;
}

}
//task 4
{
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
    
    return 0;
}

}
//task 5
{
const int SIZE = 5;
bool checkBalance(int* arr) {
    int sumR = 0;
    int sumL = arr[0];
    for (size_t i = 1; i < SIZE; i++)
        sumR += arr[i];
    for (size_t i = 1; i < SIZE; i++) {
        if (sumL != sumR) {
            sumR -= arr[i];
            sumL += arr[i];
        }
        else 
            return true; 
    }
    return false;
}
int main()
{
    int arr[SIZE] = {10, 1, 2, 3, 4};
    
    if(checkBalance(arr))
        cout<<"true \n";
    else
        cout<<"false \n";
    
    return 0;
}

}