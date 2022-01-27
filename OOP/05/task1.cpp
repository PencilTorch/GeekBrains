#include <iostream>
using namespace std;

template <class T>
class Pair1 {
public:
    Pair1(T first, T second) : m_first(first), m_second(second) {}
    T first() const {
        return m_first;
    }
    T second() const {
        return m_second;
    }
private:
    T m_first;
    T m_second;
};

int main()
{
    Pair1<int> p1(6, 9);
	cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

	const Pair1<double> p2(3.4, 7.8);
	cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

    return 0;
}

