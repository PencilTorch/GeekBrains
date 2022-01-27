#include <iostream>
#include <string>
using namespace std;

template <typename T1, typename T2>
class Pair1 {
public:
    Pair1(T1 text, T2 date) : m_text(text), m_date(date) {}
    
    T1 first() const {
        return m_text;
    }

    T2 second() const {
        return m_date;
    }
protected:
    T1 m_text;
    T2 m_date;
};

template<typename T>
class StringValuePair : public Pair1<string, T> {
public:
    StringValuePair(string text, T date) : Pair1<string, T>(text, date) {}
private:
    //string m_text;
    //T m_date;
};

int main()
{
    Pair1<string, int> pair("pair", 7);
    cout << pair.first() << " " << pair.second() << endl;
  
    StringValuePair<int> svp("Amazing", 7);
    std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';
    
    return 0;
}


