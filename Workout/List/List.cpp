#include <iostream>

using namespace std;

class List {
public:
    List() {
        Size = 0;
        head = nullptr;
    }
    ~List() {
        Node* temp = nullptr;
        while (Size) {
            temp = head;
            head = head->pNext;
            delete temp;
            --Size;
        }
    }
    void add(int date) {
        if (head == nullptr) {
            head = new Node(date);
        }
        else {
            Node* current = this->head;
            while (current->pNext != nullptr)
                current = current->pNext;
            current->pNext = new Node(date);
        }
        ++Size;
    }

    int getSize() const {
        return Size;
    }
    int& operator[](const int index) {
        int counter = 0;
        Node* current = this->head;
        while (current != nullptr) {
            if (counter == index) {
                return current->data;
            }
            current = current->pNext;
            ++counter;
        }
    }

private:
    struct Node {
        Node(int d = 0, Node* other = nullptr) : data(d), pNext(other) {}
        int data;
        Node* pNext;
    };

    int Size;
    Node* head;
};

double average(List& const lst) {
    int lastData = lst[lst.getSize() - 1];
    double sum = 0;
    int counter = 0;
    for (int i = 0; i < lst.getSize()-1; ++i) {
        if (lst[i] > lastData) {
            sum += lst[i];
            ++counter;
        }
    }
    if (sum == 0)
        return 0;
    else
        return sum / static_cast<double>(counter);
}

int minData(List& const lst) {
    int temp = lst[0];
    for (int i = 1; i < lst.getSize(); ++i) {
        if (lst[i] < temp)
            temp = lst[i];
    }
    return temp;
}

void negToMin(List& lst) {
    int min = minData(lst);
    for (int i = 0; i < lst.getSize(); ++i) {
        if (lst[i] < 0)
            lst[i] = min;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    List lst;
    cout << "Задание 1:" << endl;
    cout << "Введите числа:" << endl;
    int temp = 0;
    cin >> temp;
    while (temp != 999) {
        lst.add(temp);
        cin >> temp;
    }
    cout << "Среднее арифметическое: " << average(lst) << endl;

    cout << "Задание 2:" << endl;
    List lst2;
    cout << "Введите числа:" << endl;
    for (int i = 0; i < 10; i++) {
        cin >> temp;
        lst2.add(temp);
    }
    int min = minData(lst2);
    cout << "Минимальный элемент: " << min << endl;
    negToMin(lst2);
    cout << "Получившийся список: " << endl;
    for (int i = 0; i < lst2.getSize(); ++i) {
        cout << lst2[i] << endl;
    }


    return 0;
}