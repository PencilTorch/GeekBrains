#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

mutex m1;

class ChocolateBoiler {
private:
    ChocolateBoiler() {
        _empty = true;
        _boiled = false;
    }
    ~ChocolateBoiler() {
        if (theSingleInstance != nullptr)
            delete theSingleInstance;
    }
    ChocolateBoiler(const ChocolateBoiler& other) = delete;
    ChocolateBoiler& operator=(const ChocolateBoiler& other) = delete;
    static ChocolateBoiler* theSingleInstance;
    bool _empty;
    bool _boiled;
public:
    static ChocolateBoiler* getInstance() {
        m1.lock();
        if (theSingleInstance == nullptr)
            theSingleInstance = new ChocolateBoiler();
        m1.unlock();
        return theSingleInstance;
    }
    bool isEmpty() const {
        return _empty;
    }
    bool isBoiled() const {
        return _boiled;
    }
    void fill() {
        if (isEmpty()) {
            _empty = false;
            _boiled = false;
        }
    }
    void drain() {
        if (!isEmpty() && isBoiled()) {
            _empty = true;
        }
    }
    void boil() {
        if (!isEmpty() && !isBoiled()) {
            _boiled = true;
        }
    }
};
ChocolateBoiler* ChocolateBoiler::theSingleInstance = nullptr;

void func1() {
    ChocolateBoiler* chb1 = ChocolateBoiler::getInstance();
    cout << chb1->isEmpty() << endl;
    chb1->fill();
}

void func2() {
    ChocolateBoiler* chb2 = ChocolateBoiler::getInstance();
    cout << chb2->isEmpty() << endl;
}

int main() {
    thread th1(func1);
    thread th2(func2);
    th1.join();
    th2.join();

    return 0;
}