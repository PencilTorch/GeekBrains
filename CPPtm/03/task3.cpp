#include <iostream>

using namespace std;

//шаблонный класс-обёртка для своего класса-итератора
template<typename T>
class myArray {
public:
    class Iterator;
    myArray() {
        arr = nullptr;
        Size = 0;
    }
    myArray(size_t _size = 1) : Size(_size) {
        arr = new T[Size];
    }
    ~myArray() {
        delete[] arr;
    }
    T& operator[](const size_t it) {
        if (it > 0 && it < Size)
            return arr[it];
        return arr[0];
    }
    Iterator begin() { return arr; }
    Iterator end() { return arr + Size; }
//класс-итератор    
class Iterator {
public:
    Iterator(T* curr) : current(curr) {}
    T& operator++(int i) {
        Iterator tmp(current);
        ++current;
        return tmp;
    }
    T& operator--(int i) {
        Iterator tmp(current);
        --current;
        return tmp;
    }
    T& operator++() { return *++current; }
    T& operator--() { return *--current; }
    T& operator*() { return *current; }
    T* operator->() { return current; }
    bool operator!=(const Iterator it) {
        return current != it.current;
    }
    bool operator==(const Iterator it) {
        return current == it.current;
    }
private:
    T* current;
};

private:
    T* arr;
    size_t Size;
};


int main() {
    myArray<int> arr(10);
    auto it = myArray<int>::Iterator(arr.begin());
    for (; it != arr.end(); ++it) {
        *it = rand();
    }

    for (const auto& it : arr) {
        cout << it << " ";
    }
    
    return 0;
}
