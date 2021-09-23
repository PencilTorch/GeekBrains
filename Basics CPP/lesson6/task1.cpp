//task 1
#include <iostream>
using namespace std;
#define SIZE 8

int main() {
double arr[SIZE] = {775, -832, 45.0, 2.98, -0.0, 2.65e02, 15248, -0.85e-01};
for(int i=0; i < SIZE; i++){
        if(arr[i] == (int)arr[i])
                  cout<<arr[i]<<" ";
}
    
system("pause");
return 0;
}

