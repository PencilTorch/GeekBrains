//task 5
#include <iostream>
using namespace std;

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
    
    system("pause");
    return 0;
}

