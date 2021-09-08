#include <iostream>
using namespace std;

int main() {
unsigned int n;
cin>> n;
if(n < 0 || n == 0 || n == 1) {
    cout<< "is a not prime number \n";
}
else {
    bool f = true;
    for (size_t i = 2; i <= n/2; i++)
    {
        if (n%i == 0)
        {
            f = false;
            break;
        }
    }
    if(f) cout<< "is a prime number \n";
    else cout<< "is a not prime number \n";
}

 system("pause");
 return 0;   
}
