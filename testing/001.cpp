//наибольший интервал для сна
#include <iostream>
using namespace std;

int main() {
    int T, S, D, E;
    cin >> T >> S >> D >> E;
    T *= 60;
    int Id, Ie, Ik;
    D > S ? Id = D - S : Id = S - D;
    T > E ? Ik = T - E : Ik = E - T;
    D > Ik ? Ie = D - Ik : Ie = Ik - D;
    int max1, max2;
    S > Id ? max1 = S : max1 = Id;
    Ie > E ? max2 = Ie : max2 = E;
    max1 > max2 ? cout << max1 : cout << max2;

    return 0;
}