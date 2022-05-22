#pragma once
#include <iostream>

class Pizza {
public:
	virtual ~Pizza() {}
	virtual void prepare(std::string&) = 0; //подготовка
	virtual void bake() = 0; //выпечка
	virtual void cut() = 0; //нарезка
	virtual void box() = 0; //упаковка
};

class CheesePizza :public Pizza {
public:
	CheesePizza(std::string& type) {
		prepare(type);
	}
	virtual ~CheesePizza() {}

	void prepare(std::string &type) override {
		std::cout << "prapare Cheese Pizza..." << std::endl;
		bake();
		cut();
		box();
	}
	void bake() override {
		std::cout << "bake Cheese Pizza..." << std::endl;
	}
	void cut() override {
		std::cout << "cut Cheese Pizza..." << std::endl;
	}
	void box() override {
		std::cout << "box Cheese Pizza..." << std::endl;
	}

};
class GreekPizza :public Pizza {
public:
	GreekPizza(std::string& type) {
		prepare(type);
	}
	virtual ~GreekPizza() {}

	void prepare(std::string &type) override {
		std::cout << "prapare Greek Pizza..." << std::endl;
		bake();
		cut();
		box();
	}
	void bake() override {
		std::cout << "bake Greek Pizza..." << std::endl;
	}
	void cut() override {
		std::cout << "cut Greek Pizza..." << std::endl;
	}
	void box() override {
		std::cout << "box Greek Pizza..." << std::endl;
	}
};
class PepperoniPizza :public Pizza {
public:
	PepperoniPizza(std::string& type) {
		prepare(type);
	}
	virtual ~PepperoniPizza() {}

	void prepare(std::string &type) override {
		std::cout << "prapare Pepperoni Pizza..." << std::endl;
		bake();
		cut();
		box();
	}
	void bake() override {
		std::cout << "bake Pepperoni Pizza..." << std::endl;
	}
	void cut() override {
		std::cout << "cut Pepperoni Pizza..." << std::endl;
	}
	void box() override {
		std::cout << "box Pepperoni Pizza..." << std::endl;
	}
};
