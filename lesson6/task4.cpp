//task 4
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool combineFile(string* first, string* second, string* combo) {
    string str;
    ifstream fin;
    fin.open(*first);
    if (fin.is_open()) {
        string temp;
        while (!fin.eof()) {
            getline(fin,temp);
        }
        fin.close();
        str = temp;
    }
    else {
        cout << "Don't open first file " << *first << endl;
        return false;
    }
    fin.open(*second);
    if (fin.is_open()) {
        string temp;
        while (!fin.eof()) {
            getline(fin, temp);
        }
        fin.close();
        str = str + temp;
    }
    else {
        cout << "Don't open second file " << *second << endl;
        return false;
    }
    ofstream fout;
    fout.open(*combo);
    if (fout.is_open()) {
        fout << str;
        fout.close();
        return true;
    }
    else {
        cout << "Error. Can not open file.";
        return false;
    }
}

int main()
{
    cout << "Combine 2 file in one!\n";
    cout<<"Input first file name: ";
    string first;
    getline(cin, first);
    cout<<"Input second file name: ";
    string second;
    getline(cin, second);
    cout << "Input combo file name: ";
    string combo;
    getline(cin, combo);
    if (combineFile(&first, &second, &combo)) {
        cout << "file " << first << " and file " << second << " successfully combine in " << combo << endl;
    }
    
    return 0;
}

