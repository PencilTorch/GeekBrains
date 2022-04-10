#include <iostream>
using namespace std;

template <typename T>
void Swap(T **fst, T **snd) {
    T* temp = *fst;
    *fst = *snd;
    *snd = temp;
}

int main() {
    int p = 5;
    int v = 10;
    int* pp = &p;
    int* pv = &v;
    Swap(&pp, &pv);
    cout << *pp << endl;
    cout << *pv << endl;
    
    return 0;
}