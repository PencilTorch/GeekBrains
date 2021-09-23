#include <iostream>
using namespace std;

int main() {
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

 system("pause");
 return 0;   
}
