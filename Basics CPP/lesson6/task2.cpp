//task 2
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int SIZE = 4;

void __fastcall printArr(int** arr,const int size) {
    for(int i = 0; i < size; i++){
             for(int j = 0; j < SIZE; j++){
                     cout<< arr[i][j] <<" ";
             }
             cout<<endl;
     }
}

void __fastcall fillArr(int** arr, const int size){
     srand(static_cast<unsigned int>(time(0)));
     for(int i = 0; i < size; i++){
             for(int j = 0; j < SIZE; j++){
                     arr[i][j] = rand() % 1000;
             }
     }
}

int main()
{
    int** pArr = new int* [SIZE];
    for(int i = 0; i < SIZE; i++){
            pArr[i] = new int[SIZE];
    }
    fillArr(pArr, SIZE);
    printArr(pArr, SIZE);
    
    for(int i = 0; i < SIZE; i++){
            delete [] pArr[i];
    }
    delete [] pArr;
    pArr = NULL;
    
    system("pause");
    return 0;
}

