#include <iostream>
#include "Builder.h"

int main() {
    Vacation vacation;
    FirstDayActionBuilder fdab;
    SecondDayActionBuilder sdab;
    ThirdDayActionBuilder tdab;
    Actions* af = vacation.createActionsDay(fdab);
    Actions* as = vacation.createActionsDay(sdab);
    Actions* at = vacation.createActionsDay(tdab);
    std::cout << "First day events:" << std::endl;
    af->getActions();
    std::cout << std::endl;

    std::cout << "Second day events:" << std::endl;
    as->getActions();
    std::cout << std::endl;

    std::cout << "Third day events:" << std::endl;
    at->getActions();

    return 0;
}
