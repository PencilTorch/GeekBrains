//task 5
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string filename;
    cout << "Input file name: ";
    getline(cin, filename);
    ifstream fin;
    fin.open(filename);
    if (fin.is_open()) {
        string text;
        while (!fin.eof()) {
            string temp;
            getline(fin, temp);
            text = text + " " + temp;
        }
        cout << "Input loocking word: ";
        string findWord;
        cin >> findWord;
        if (text.find(findWord) != string::npos) {
            cout << "Yes, we found " << findWord << endl;
        }
        else {
            cout << "We can not find " << findWord << endl;
        }
        fin.close();
    }
    else {
        cout << "file " << filename << " don't open!" << endl;
    }
    
    return 0;
}

