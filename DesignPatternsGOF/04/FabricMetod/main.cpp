#include "FabricMetod.h"
using namespace std;

int main() {
    std::string type = "";
    std::cout << "What pizza?" << std::endl;
    cin >> type;
    Pizza* pizza = nullptr;
    PizzaFactory* pf = nullptr;
    CheesePizzaFactory* cpf = new CheesePizzaFactory;
    GreekPizzaFactory* gpf = new GreekPizzaFactory;
    PepperoniPizzaFactory* ppf = new PepperoniPizzaFactory;

    if (type == "cheese") {
        pf = cpf;
        pizza = pf->createPizza(type);
    }
    else if (type == "greek") {
        pf = gpf;
        pizza = pf->createPizza(type);
    }
    else if (type == "pepperoni") {
        pf = ppf;
        pizza = pf->createPizza(type);
    }
    
    return 0;
}