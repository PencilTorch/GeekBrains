#include <iostream>
#define HP_COEF 10
#define ATK_COEF 2
#define DEF_COEF 2

class Monster {
public:
    Monster(const std::string& type, int hp = 0, int atk = 0, int def = 0) : _type(type), _hp(hp), _atk(atk), _def(def) {}
    virtual ~Monster() {}

    void changeHp(int change) { _hp += change; }
    void changeAtk(int change) { _atk += change; }
    void changeDef(int change) { _def += change; }

    int getHp() const { return _hp; }
    int getAtk() const { return _atk; }
    int getDef() const { return _def; }
    void printCharacters() const {
        std::cout << _type << ": " << _hp << ", " << _atk << ", " << _def << std::endl;
    }

    virtual void setLvl(int lvl) = 0;
    virtual Monster* clone() const = 0;
private:
    int _hp;
    int _atk;
    int _def;
    std::string _type;
};

class MonstersLevel : public Monster {
public:
    MonstersLevel(const std::string& type, int hp = 0, int atk = 0, int def = 0) : Monster(type, hp, atk, def) {};
    void setLvl(int lvl) override {
        if (lvl > 0 && lvl <= 10) {
            changeHp(lvl * HP_COEF);
            changeAtk(lvl * ATK_COEF);
            changeDef(lvl * DEF_COEF);
        }
    }
    Monster* clone() const override {
        return new MonstersLevel(*this);
    }
};

int main() {
    Monster* goblin_basic = new MonstersLevel("goblin", 10, 1, 1);
    Monster* goblin_1lvl = goblin_basic->clone();
    goblin_1lvl->setLvl(1);
    Monster* goblin_2lvl = goblin_basic->clone();
    goblin_2lvl->setLvl(2);

    goblin_basic->printCharacters();
    goblin_1lvl->printCharacters();
    goblin_2lvl->printCharacters();

    delete goblin_2lvl;
    delete goblin_1lvl;
    delete goblin_basic;

    return 0;
}
