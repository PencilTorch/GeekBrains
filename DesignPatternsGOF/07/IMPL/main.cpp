#include "Player.h"



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