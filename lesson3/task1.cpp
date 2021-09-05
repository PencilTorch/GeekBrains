//task 1
#include <iostream>
using namespace std;
int main()
{
    const int a = 5, b = 10, c = 15, d = 20;
    float result = a * (b + (static_cast<float>(c) / d));
    cout << result << endl;

    return 0;
}

