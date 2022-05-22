#pragma once
#include "pizza.h"

struct PizzaFactory {
	virtual ~PizzaFactory() {}
	virtual Pizza* makePizza(std::string& type) = 0;
};

struct CheesePizzaFactory : public PizzaFactory {
	Pizza* makePizza(std::string& type) override {
		return new CheesePizza(type);
	}
};

struct GreekPizzaFactory : public PizzaFactory {
	Pizza* makePizza(std::string& type) override {
		return new GreekPizza(type);
	}
};

struct PepperoniPizzaFactory : public PizzaFactory {
	Pizza* makePizza(std::string& type) override {
		return new PepperoniPizza(type);
	}
};

class Order {
public:
	~Order() {
		delete pizza;
	}

	Pizza* orderPizza(std::string &type) {
		if (type == "cheese") {
			CheesePizzaFactory cpf;
			pizza = cpf.makePizza(type);
		}
		else if (type == "greek") {
			GreekPizzaFactory gpf;
			pizza = gpf.makePizza(type);
		}
		else if (type == "pepperoni") {
			PepperoniPizzaFactory ppf;
			pizza = ppf.makePizza(type);
		}
		return pizza;
	}
private:
	Pizza* pizza = nullptr;
};


