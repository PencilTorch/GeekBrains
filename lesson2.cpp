#include <iostream>

using std::cout;
using std::endl;

const int SIZE = 3;

int main()
{
    //task 1
    {
        short int shInt = 32767; //short
        int i = 0; //int
        long long ll = 9223372036854775807; //long long
        char c = 'A'; //char
        bool f = true;
        float fi = 555.5f; //float
        double d = 123.456; //double
    }
    //task 2
    
        enum StatusCell {zero, cross, blank}; //for cross-zero
    
    //task 3
    
        StatusCell area[SIZE][SIZE] {{zero,cross,blank}, {cross,cross,zero}, {zero,blank,zero}};
    
    //task 4

        struct CrissCross
        {
            char player1[20];
            char player2[20];
            int areaSize = SIZE; //default
            char zero = 0;    //key for zero by default
            char cross = 1;   //key for cross by default
            char blank = 2;   //key for empty by default
            bool flag = false;
        };

    //task 5

        struct MyStruct
        {
            union MyData
            {
                int a;
                float f;
                char c;
            };
            bool isInt : 1;
            bool isFloat : 1;
            bool isChar : 1;
        };

        MyStruct ms;
        ms.isInt = true;
        cout << sizeof(MyStruct);

    return 0;
}

