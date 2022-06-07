#pragma once
#include "Memento.h"

class Impl {
public:
    Impl(float hp, int speed, const std::string& name) : _hp(hp), _speed(speed), _name(name) {}
    float getHp() const {
        return _hp;
    }
    int getSpeed() const {
        return _speed;
    }
    const std::string& getName() const {
        return _name;
    }
    void SetHp(float hp) { _hp = hp; }
    void SetSpeed(int speed) { _speed = speed; }
private:
    float _hp;
    int _speed;
    std::string _name;
};

class Player {
public:
    Player(float hp, int speed, const std::string& name) : pImpl(new Impl(hp, speed, name)) {}
    ~Player() {
        delete pImpl;
    }
    void changeSpeed(int change) {
        createMemento();
        pImpl->SetSpeed(change);
    }
    void changeHp(float change) {
        createMemento();
        pImpl->SetHp(change);
    }
    void undo() {
        reinstateMemento();
        if (mem.size() > 0) {
            m = mem[mem.size() - 1];
            pImpl->SetHp(m.GetHp());
            pImpl->SetSpeed(m.GetSpeed());
            mem.pop_back();
            std::ofstream fout;
            fout.open(PATH, std::ofstream::binary | std::ofstream::app);
            if (fout.is_open()) {
                for (auto it : mem)
                    fout.write((char*)&it, sizeof(Memento));
            }
            fout.close();
        }
        else
            std::cout << "Nothing to undo!" << std::endl;
    }
    float getHp() const {
        return pImpl->getHp();
    }
    int getSpeed() const {
        return pImpl->getSpeed();
    }
    const std::string& getName() const {
        return pImpl->getName();
    }
private:
    void createMemento() {
        m.SetHp(pImpl->getHp());
        m.SetSpeed(pImpl->getSpeed());
        std::ofstream fout;
        fout.open(PATH, std::ofstream::binary | std::ofstream::app);
        if (fout.is_open()) {
            fout.write((char*)&m, sizeof(Memento));
        }
        fout.close();
    }
    void reinstateMemento() {
        std::ifstream fin;
        fin.open(PATH);
        if (fin.is_open()) {
            mem.clear();
            while (fin.read((char*)&m, sizeof(Memento))) {
                mem.push_back(m);
            }
            fin.close();
        }
        std::remove(PATH);
    }

    Memento m;
    std::vector<Memento> mem;
    Impl* pImpl = nullptr;
};