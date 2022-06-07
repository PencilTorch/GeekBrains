#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#define PATH "path.bin"

class Memento {
public:
    Memento(float hp = 0, int speed = 0) : _hp(hp), _speed(speed) {}
    Memento(const Memento& other) {
        _hp = other._hp;
        _speed = other._speed;
    }
    Memento& operator=(const Memento& other) {
        _hp = other.GetHp();
        _speed = other.GetSpeed();
        return *this;
    }
    void SetHp(float hp) { _hp = hp; }
    void SetSpeed(int speed) { _speed = speed; }
    float GetHp() const {
        return _hp;
    }
    int GetSpeed() const {
        return _speed;
    }
private:
    float _hp;
    int _speed;
};
