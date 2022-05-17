#include <iostream>

using namespace std;


class ChocolateBoiler {
private:
    ChocolateBoiler() {
        _empty = true;
        _boiled = false;
    }
    ChocolateBoiler(const ChocolateBoiler& other) = delete;
    ChocolateBoiler& operator=(const ChocolateBoiler& other) = delete;
    bool _empty;
    bool _boiled;
public:
    static ChocolateBoiler& getInstance() {
        static ChocolateBoiler theSingleInstance;
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


int main() {
    ChocolateBoiler::getInstance();
    cout << ChocolateBoiler::getInstance().isEmpty();
    ChocolateBoiler::getInstance().fill();
    cout << ChocolateBoiler::getInstance().isEmpty();

    return 0;
}