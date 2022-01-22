#include "ArrayInt.h"
#include <iostream>

void ArrayInt::erase() {
    delete[] m_data;
    m_data = nullptr;
    m_length = 0;
}

int ArrayInt::getLength() {
    return m_length;
}

int& ArrayInt::operator[](int index) {
    assert(index >= 0 && index < m_length);
    return m_data[index];
}

void ArrayInt::resize(int newLength) {
    if (newLength == m_length)
        return;
    if (newLength <= 0) {
        erase();
        return;
     }
     int *data = new int[newLength];
     if (m_length > 0) {
         int elementsToCopy = (newLength > m_length) ? m_length : newLength;
         for (int index=0; index < elementsToCopy ; ++index)
             data[index] = m_data[index];
      }
      delete[] m_data;
      m_data = data;
      m_length = newLength;
}

void ArrayInt::insertBefore(int value, int index) {
    assert(index >= 0 && index <= m_length);
    int* data = new int[m_length + 1];
    for (int before = 0; before < index; ++before) {
        data[before] = m_data[before];
    }
    data[index] = value;
    for (int after = index; after < m_length; ++after) {
        data[after + 1] = m_data[after];
    }
    delete[] m_data;
    m_data = data;
    ++m_length;
}

void ArrayInt::push_back(int value) {
    insertBefore(value, m_length);
}

void ArrayInt::pop_back() {
    --m_length;
    int* data = new int[m_length];
    for (int before = 0; before < m_length; ++before) {
        data[before] = m_data[before];
    }
    delete[] m_data;
    m_data = data;
}

void ArrayInt::pop_front() {
    int* data = new int[m_length-1];
    for (int after = 1; after < m_length; ++after) {
        data[after - 1] = m_data[after];
    }
    delete[] m_data;
    m_data = data;
    --m_length;
}

void ArrayInt::sortArray() {
    int temp, pos;
    for (int i = 1; i < m_length; ++i) {
        temp = m_data[i];
        pos = i - 1;
        while (pos >= 0 && m_data[pos] > temp) {
            m_data[pos + 1] = m_data[pos];
            --pos;
        }
        m_data[pos + 1] = temp;
    }
}

void ArrayInt::printArray() {
    if (m_length > 0) {
        for (int it = 0; it < m_length; ++it) {
            std::cout << m_data[it] << " ";
        }
        std::cout << "\n";
    }
    else {
        std::cout << "array is empty\n";
    }
}
