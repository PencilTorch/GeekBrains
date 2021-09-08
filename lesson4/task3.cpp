#include <iostream>
using namespace std;

const int SIZE = 50;

int main() {
for (size_t i = 1; i <= SIZE; i++)
{
    if(i == 1) cout<< 1 << " ";
    else if(i % 2 != 0) cout<< i << " ";
}
cout<< endl;

 system("pause");
 return 0;   
}
