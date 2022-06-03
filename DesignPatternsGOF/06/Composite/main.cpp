#include "Composite.h"

int main() {
    ComboFood* morning = MorningMenu();
    morning->addFood(new ChocolatePancake);

    std::cout << morning->getName();
    std::cout << "\n-------------\n";
    std::cout << morning->getPrice();

    return 0;
}