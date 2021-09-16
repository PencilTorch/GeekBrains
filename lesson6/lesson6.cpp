//task 1
{
#include <iostream>
using namespace std;

void __fastcall printArr(int* arr,const int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void __fastcall fillArr(int* arr, const int size){
     for(size_t i = 0, k = 1; i < size; i++, k *= 2){
             arr[i] = k;
     }
}

int main()
{
    int SIZE=0;
    cout<<"Input massive size: ";
    cin>>SIZE;
    static_cast<const int>(SIZE);
    int* pArr = new (std::nothrow) int[SIZE];
    if(pArr != NULL){
            fillArr(pArr, SIZE);
            printArr(pArr, SIZE);
    }
    else {
        cout<<"Error! Can not allocate memory!"<<endl;
        }
    delete [] pArr;
    
    system("pause");
    return 0;
}
}
//task 2
{
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int SIZE = 4;

void __fastcall printArr(int** arr,const int size) {
    for(int i = 0; i < size; i++){
             for(int j = 0; j < SIZE; j++){
                     cout<< arr[i][j] <<" ";
             }
             cout<<endl;
     }
}

void __fastcall fillArr(int** arr, const int size){
     srand(static_cast<unsigned int>(time(0)));
     for(int i = 0; i < size; i++){
             for(int j = 0; j < SIZE; j++){
                     arr[i][j] = rand() % 1000;
             }
     }
}

int main()
{
    int** pArr = new int* [SIZE];
    for(int i = 0; i < SIZE; i++){
            pArr[i] = new int[SIZE];
    }
    fillArr(pArr, SIZE);
    printArr(pArr, SIZE);
    
    for(int i = 0; i < SIZE; i++){
            delete [] pArr[i];
    }
    delete [] pArr;
    pArr = NULL;
    
    system("pause");
    return 0;
}
}
//task 3
{
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void makeFile(){
    string filename;
    getline(cin, filename);
    filename = filename + ".txt";
    ofstream outf;
    outf.open(filename);
    if (outf.is_open()) {
        cout << "Input something text: \n";
        getline(cin, filename);
        outf << filename;
        outf.close();
    }
    else{
        cout<<"file "<<filename<<"don't open! \n";
    }
}

int main()
{
    cout<<"Input first file name: ";
    makeFile();
    cout<<"Input second file name: ";
    makeFile();
    
    return 0;
}
}
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


