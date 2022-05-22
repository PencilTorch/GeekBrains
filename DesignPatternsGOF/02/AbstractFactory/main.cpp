#include <iostream>
#include "AbstractFactory.h"

int main() {
    std::cout << "choose type the pizza:\n1 - cheese,\n2 - greek,\n3 - pepperoni\n";
    Order order1;
    int n;
    std::string typePizza;
    std::cin >> n;
    switch (n) {
    case 1:
        typePizza = "cheese";
        order1.orderPizza(typePizza);
        break;
    case 2:
        typePizza = "greek";
        order1.orderPizza(typePizza);
        break;
    case 3:
        typePizza = "pepperoni";
        order1.orderPizza(typePizza);
        break;
    default:
        break;
    }
    
    
    return 0;
}
