//task 2
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    n = n <= 21 ? 21 - n : (n - 21) * 2;
    cout << n << endl;

    return 0;
}