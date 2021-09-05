//task 3
#include <iostream>
using namespace std;
int main()
{
    const int DIM1 = 3;
    const int DIM2 = 3;
    const int DIM3 = 3;

    int arr[DIM1][DIM2][DIM3] = { {{0,1,2},{3,4,5},{6,7,8}}, {{9,10,11},{12,13,14},{15,16,17}}, {{18,19,20},{21,22,23},{24,25,26}} };
    int* ptr_arr = &arr[1][1][1];
    cout << *ptr_arr << endl;

    return 0;
}