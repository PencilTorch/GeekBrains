#include "Decorator.h"

int main() {
    HouseBlend* hb = new HouseBlend;
    std::cout << hb->getDescription() << std::endl;
    std::cout << hb->cost() << std::endl;
    Decorator* chocoDec = new ChocoDecor(hb);
    Decorator* creamDec = new CreamDecor(hb, 0.45);

    std::cout << chocoDec->getDescription();
    std::cout << chocoDec->cost() << std::endl;
    std::cout << creamDec->getDescription();
    std::cout << creamDec->cost() << std::endl;

    return 0;
}
