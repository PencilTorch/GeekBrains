#include "Memento.h"


class Player {
public:
    Player(float hp, int speed, const std::string& name) : _hp(hp), _speed(speed), _name(name) {}
    void changeSpeed(int change) {
        createMemento();
        _speed = change;
    }
    void changeHp(float change) {
        createMemento();
        _hp = change;
    }
    void undo() {
        reinstateMemento();
        if (mem.size() > 0) {
            m = mem[mem.size() - 1];
            _hp = m.GetHp();
            _speed = m.GetSpeed();
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
        return _hp;
    }
    int getSpeed() const {
        return _speed;
    }
    const std::string& getName() const {
        return _name;
    }
    
private:
    void createMemento() {
        m.SetHp(_hp);
        m.SetSpeed(_speed);
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
    float _hp;
    int _speed;
    std::string _name;
    Memento m;
    std::vector<Memento> mem;
};

int main() {
    Player player1(100.0, 0, "Uasya");
    player1.changeHp(90);
    player1.changeSpeed(50);
    player1.changeHp(75);
    player1.changeSpeed(85);
    std::cout << player1.getName() << ": " << player1.getHp() << ", " << player1.getSpeed() << std::endl;
    player1.undo();
    std::cout << player1.getName() << ": " << player1.getHp() << ", " << player1.getSpeed() << std::endl;
    player1.undo();
    std::cout << player1.getName() << ": " << player1.getHp() << ", " << player1.getSpeed() << std::endl;
    player1.undo();
    std::cout << player1.getName() << ": " << player1.getHp() << ", " << player1.getSpeed() << std::endl;
    player1.undo();
    std::cout << player1.getName() << ": " << player1.getHp() << ", " << player1.getSpeed() << std::endl;
    player1.undo();

    return 0;
}