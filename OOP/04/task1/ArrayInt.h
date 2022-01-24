#ifndef ARRAYINT_H
#define ARRAYINT_H

#include <cassert> // for assert()

class ArrayInt {
private:
    int m_length;
    int* m_data;

public:
    ArrayInt() : m_length(0), m_data(nullptr) { }

    ArrayInt(int length) : m_length(length) {
        assert(length >= 0);
        if (length > 0)
            m_data = new int[length];
        else
            m_data = nullptr;
    }

    ~ArrayInt() {
        delete[] m_data;
    }

    void erase();
    int getLength();
    int& operator[](int index);
    void resize(int newLength);
    void insertBefore(int value, int index);
    void push_back(int value);
    void pop_back();
    void pop_front();
    void sortArray();
    void printArray();
};

#endif
