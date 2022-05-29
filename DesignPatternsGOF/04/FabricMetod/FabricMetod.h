#pragma once
#include <iostream>
#include <string>

class Pizza {
public:
	virtual void prepare(std::string) {};
	virtual void bake() {};
	virtual void cut() {};
	virtual void box() {};
};
class CheesePizza :public Pizza {};
class GreekPizza :public Pizza {};
class PepperoniPizza :public Pizza {};

Pizza* orderPizza(std::string type) {
	Pizza* pizza = nullptr;
	if (type == "cheese") {
		pizza = new CheesePizza;
	}
	else if (type == "greek") {
		pizza = new GreekPizza;
	}
	else if (type == "pepperoni") {
		pizza = new PepperoniPizza;
	}
	return pizza;
}

class PizzaFactory {
public:
	virtual Pizza* createPizza(std::string& type) = 0;
	virtual ~PizzaFactory() {}
};

class CheesePizzaFactory : public PizzaFactory {
public:
	Pizza* createPizza(std::string& type) override {
		return orderPizza(type);
	}
};

class GreekPizzaFactory : public PizzaFactory {
public:
	Pizza* createPizza(std::string& type) override {
		return orderPizza(type);
	}
};

class PepperoniPizzaFactory : public PizzaFactory {
public:
	Pizza* createPizza(std::string& type) override {
		return orderPizza(type);
	}
};
