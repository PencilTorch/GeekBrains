#include <iostream>
using namespace std;

template <typename T>
<<<<<<< HEAD
void Swap(T** fst, T** snd) {
=======
void Swap(T **fst, T **snd) {
>>>>>>> a5ec6d5f417a2e4dc6f4dc89e04d91cf4518c714
    T* temp = *fst;
    *fst = *snd;
    *snd = temp;
}

int main() {
<<<<<<< HEAD
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
=======
    int p = 5;
    int v = 10;
    int* pp = &p;
    int* pv = &v;
    Swap(&pp, &pv);
    cout << *pp << endl;
    cout << *pv << endl;
>>>>>>> a5ec6d5f417a2e4dc6f4dc89e04d91cf4518c714
    
    return 0;
}