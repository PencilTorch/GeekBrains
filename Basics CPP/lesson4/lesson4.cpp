#include <iostream>
using namespace std;

int main() {
//task 1
{
int a , b;
 cin >> a >> b;
 if((a + b) >= 10 && (a + b) <= 20) cout<<"true\n";
 else cout<< "false\n";
 
}
//task 2
{
const int A = 5;
const int B = 5;
if((A == 10 && B == 10) || (A + B) == 10) cout<< "true" <<endl;
else cout<< "false" <<endl;
}
//task 3
{
const int SIZE = 50;
for (size_t i = 1; i <= SIZE; i++) {
    if(i == 1) cout<< 1 << " ";
    else if(i % 2 != 0) cout<< i << " ";
}
cout<< endl;
}
//task 4
{
unsigned int n;
cin>> n;
if(n < 0 || n == 0 || n == 1) {
    cout<< "is a not prime number \n";
}
else {
    bool f = true;
    for (size_t i = 2; i <= n/2; i++) {
        if (n%i == 0) {
            f = false;
            break;
        }
    }
    if(f) cout<< "is a prime number \n";
    else cout<< "is a not prime number \n";
}
}
//task 5
{
short int year;
cin>> year;
if (year % 4 == 0) {
    if(year % 100 == 0) {
        if(year % 400 == 0) cout<< "this leap year" <<endl;
        else cout<< "this year not leap" <<endl;
    }
    else cout<< "this leap year" <<endl;
}
else cout<< "this year not leap" <<endl;
}

 system("pause");
 return 0;   
}
