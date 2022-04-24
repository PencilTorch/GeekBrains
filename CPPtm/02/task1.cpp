#include <iostream>
using namespace std;

template <typename T>
void Swap(T** fst, T** snd) {
    T* temp = *fst;
    *fst = *snd;
    *snd = temp;
}

int main() {
    int one = 5;
    int two = 10;
    int* p1 = &one;
    int* p2 = &two;
    cout << "variable 1 = " << one << endl;
    cout << "variable 2 = " << two << endl;
    cout << "pointer 1 = " << *p1 << endl;
    cout << "pointer 2 = " << *p2 << endl;
    cout << "\n...Using function Swap... \n\n";
    Swap(&p1, &p2);
    cout << "variable 1 = " << one << endl;
    cout << "variable 2 = " << two << endl;
    cout << "pointer 1 = " << * p1 << endl;
    cout << "pointer 2 = " << * p2 << endl;
    
    return 0;
}