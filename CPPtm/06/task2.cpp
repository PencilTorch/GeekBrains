﻿#include <iostream>
#include <math.h>
#include <thread>
using namespace std;

bool primeNum(const unsigned long int a) {
    unsigned long i1, i2, i3, i4, i5, i6, i7, i8, bound;
    if (a == 0 || a == 1)
        return 0;
    if (a == 2 || a == 3 || a == 5 || a == 7 || a == 11 || a == 13 || a == 17 || a == 19 || a == 23 || a == 29)
        return 1;
    if (a % 2 == 0 || a % 3 == 0 || a % 5 == 0 || a % 7 == 0 || a % 11 == 0 || a % 13 == 0 || a % 17 == 0 || a % 19 == 0 || a % 23 == 0 || a % 29 == 0)
        return 0;
    bound = sqrt((double)a);
    i1 = 31; i2 = 37; i3 = 41; i4 = 43; i5 = 47; i6 = 49; i7 = 53; i8 = 59;
    while (i8 <= bound && a % i1 && a % i2 && a % i3 && a % i4 && a % i5 && a % i6 && a % i7 && a % i8)
    {
        i1 += 30; i2 += 30; i3 += 30; i4 += 30; i5 += 30; i6 += 30; i7 += 30; i8 += 30;
    }
    if (i8 <= bound ||
        i1 <= bound && a % i1 == 0 ||
        i2 <= bound && a % i2 == 0 ||
        i3 <= bound && a % i3 == 0 ||
        i4 <= bound && a % i4 == 0 ||
        i5 <= bound && a % i5 == 0 ||
        i6 <= bound && a % i6 == 0 ||
        i7 <= bound && a % i7 == 0)
        return 0;
    return 1;
}

unsigned long int ShowPrimeNumber(const unsigned int task, unsigned int& status) {
    unsigned int sum = 0;
    unsigned long int it = 2;
    while (sum < task) {
        if (primeNum(it)) {
            ++sum;
            status = (sum * 100.0) / task;
        }  
        ++it;
    }
    return --it;
}


int main() {
    unsigned long int result = 0;
    unsigned int st = 0;
    int number;
    cin >> number;
    thread th1([&]() {result = ShowPrimeNumber(number, st); });
    th1.detach();
    while (result == 0) {
        cout << "status: " << st << "%";
        system("cls");
    }
   	cout << "status: " << st << "%";
    cout << "\nresult = " << result << endl;
    
   
    return 0;
}