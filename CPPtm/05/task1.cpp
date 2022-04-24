#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <list>
#include <deque>
#include <set>

using namespace std;

template <typename T>
void uniqWordsPrint(const T& b, const T& e) {
    set<string> temp;
    temp.insert(b, e);
    copy(temp.begin(), temp.end(), ostream_iterator<string>(cout, "\n"));
}

int main() {
    setlocale(LC_ALL, "Russian");
    // три типа контейнеров
    vector<string> words1;
    list<string> words2;
    deque<string> words3;
    // заполняем их произвольным текстом
    ifstream fs("text.txt");
    if (fs.is_open()) {
        string text;
        while (fs >> text) {
            words1.push_back(text);
            words2.push_front(text);
            words3.push_back(text);
        }
        // vector
        auto it1 = begin(words1);
        auto it2 = end(words1);
        uniqWordsPrint(it1, it2);
        // list
        cout << "\n ===================== \n\n";
        auto it3 = begin(words2);
        auto it4 = end(words2);
        uniqWordsPrint(it3, it4);
        // deque
        cout << "\n ===================== \n\n";
        auto it5 = begin(words3);
        auto it6 = end(words3);
        uniqWordsPrint(it5, it6);
        
        fs.close();
    }
    else
        cout << "file dont open!\n";


    return 0;
}