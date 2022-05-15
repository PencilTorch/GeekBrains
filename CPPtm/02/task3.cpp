#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <chrono>
using namespace std;

bool vowels(const char ch) {
    constexpr int Size = 34;
    char arrVowels[Size] = { 'а', 'А', 'у', 'У', 'о', 'О', 'ы', 'Ы', 'и', 'И', 'э', 'Э', 'я', 'Я', 'ю', 'Ю',
        'ё', 'Ё', 'е', 'Е', 'a', 'A', 'e', 'E', 'i', 'I', 'u', 'U', 'y', 'Y', 'o', 'O', 'j', 'J' };
    for (int i = 0; i < Size; i++) {
        if (ch == arrVowels[i])
            return true;
    }
    return false;
}

// count_if и find
int count_if_and_find(const string& path) {
    ifstream fin(path, ios::in);
    size_t count = 0;
    if (fin.is_open()) {
        string str;
        string vowels = "аАуУоОыЫиИэЭяЯюЮёЁеЕaAeEiIuUyYoOjJ";
        while (!fin.eof()) {
            getline(fin, str);
            count += count_if(str.begin(), str.end(),
                [vowels](char ch) { return find(vowels.begin(), vowels.end(), ch) != vowels.end(); });
        }
    }
    else {
        cout << "file " << path << " don't open!\n";
    }
    fin.close();
    return count;
}

// count_if и цикл for
int count_if_and_for(const string& path) {
    ifstream fin(path, ios::in);
    size_t count = 0;
    if (fin.is_open()) {
        string str;
        while (!fin.eof()) {
            getline(fin, str);
            count += count_if(str.cbegin(), str.cend(), vowels);
        }
    }
    else {
        cout << "file " << path << " don't open!\n";
    }
    fin.close();
    return count;
}

// цикл for и find
int for_and_find(const string& path) {
    ifstream fin(path, ios::in);
    size_t count = 0;
    string vowels = "аАуУоОыЫиИэЭяЯюЮёЁеЕaAeEiIuUyYoOjJ";
    if (fin.is_open()) {
        string str;
        while (!fin.eof()) {
            getline(fin, str);
            for (string::const_iterator it = str.begin(); it != str.end(); ++it) {
                if (vowels.find(*it) != string::npos)
                    count++;
            }
        }
    }
    else {
        cout << "file " << path << " don't open!\n";
    }
    fin.close();
    return count;
}

// 2 цикла for
int two_for(const string& path) {
    ifstream fin(path, ios::in);
    size_t count = 0;
    if (fin.is_open()) {
        string str;
        while (!fin.eof()) {
            getline(fin, str);
            for (size_t it = 0; it < str.size(); ++it) {
                if (vowels(str[it]))
                    count++;
            }
        }
    }
    else {
        cout << "file " << path << " don't open!\n";
    }
    fin.close();
    return count;
}

int main() {
    setlocale(LC_ALL, "Russian");

    string path = "voyna-i-mir-tom-1.txt";

    auto begin = chrono::steady_clock::now();
    cout << "count_if и find: " << count_if_and_find(path) << endl;
    auto end = chrono::steady_clock::now();
    auto elapsed_ms = chrono::duration_cast<chrono::milliseconds>(end - begin);
    cout << "The time: " << elapsed_ms.count() << " ms\n";

    begin = chrono::steady_clock::now();
    cout << "count_if и цикл for: " << count_if_and_for(path) << endl;
    end = chrono::steady_clock::now();
    elapsed_ms = chrono::duration_cast<chrono::milliseconds>(end - begin);
    cout << "The time: " << elapsed_ms.count() << " ms\n";

    begin = chrono::steady_clock::now();
    cout << "цикл for и find: " << for_and_find(path) << endl;
    end = chrono::steady_clock::now();
    elapsed_ms = chrono::duration_cast<chrono::milliseconds>(end - begin);
    cout << "The time: " << elapsed_ms.count() << " ms\n";

    begin = chrono::steady_clock::now();
    cout << "два цикла for: " << two_for(path) << endl;
    end = chrono::steady_clock::now();
    elapsed_ms = chrono::duration_cast<chrono::milliseconds>(end - begin);
    cout << "The time: " << elapsed_ms.count() << " ms\n";

    return 0;
}