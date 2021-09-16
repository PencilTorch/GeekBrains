//task 1
#include <iostream>
using namespace std;

void __fastcall printArr(int* arr,const int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void __fastcall fillArr(int* arr, const int size){
     for(size_t i = 0, k = 1; i < size; i++, k *= 2){
             arr[i] = k;
     }
}

int main()
{
    int SIZE=0;
    cout<<"Input massive size: ";
    cin>>SIZE;
    static_cast<const int>(SIZE);
    int* pArr = new (std::nothrow) int[SIZE];
    if(pArr != NULL){
            fillArr(pArr, SIZE);
            printArr(pArr, SIZE);
    }
    else {
        cout<<"Error! Can not allocate memory!"<<endl;
        }
    delete [] pArr;
    
    system("pause");
    return 0;
}

