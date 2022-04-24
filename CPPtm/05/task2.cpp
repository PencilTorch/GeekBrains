#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

void ltrim(string& str) {
    while (str[0] == ' ')
        str.erase(0, 1);
}

pair<int, string> inserter(const string::iterator& b, const string::iterator& e) {
    string temp = "";
    int n = 0;
    copy(b, e, back_inserter(temp));
    ltrim(temp);
    n = count(temp.begin(), temp.end(), ' ') + 1;
    return { n, temp };
}

int main() {
    multimap<int, string> sentences; //контейнер
    string words;                   //строка целиком до Enter
    getline(cin, words);
    string::iterator it = words.begin();
    string::iterator it1 = words.end();
    while (it != words.end()) {
        it1 = find_if(it, it1, [](char ch) { return (ch == '.' || ch == '?' || ch == '!'); });
        if (it1 != words.end()) { 
            sentences.insert(inserter(it, it1));
            it = ++it1;           //смещаем вправо на 1, чтоб перескочить разделитель
            it1 = words.end();
        }
        else {                       //если в конце words нет точки и т.п.
            sentences.insert(inserter(it, it1));
            it = it1;
        }
    }
    
    for_each(sentences.begin(), sentences.end(), [](pair<int, string> p) 
                        { cout << p.first << " " << p.second << "\n"; });
    
    return 0;
}