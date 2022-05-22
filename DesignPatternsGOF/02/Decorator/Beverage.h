#pragma once
#include <iostream>

class Beverage { // ����������� �����
public:
	virtual ~Beverage() {}
	virtual std::string getDescription() const = 0;
	virtual double cost() const = 0;
};

class HouseBlend : public Beverage { // �������
public:
	double cost() const override {
		return 5.5;
	}
	std::string getDescription() const override {
		return "Ground coffee";
	}
};
class DarkRoast : public Beverage { // ������ �������
public:
	double cost() const override {
		return 6.0;
	}
	std::string getDescription() const override {
		return "Dark roast coffee";
	}
};
class Decaf : public Beverage { // ��� �������
public:
	double cost() const override {
		return 7.3;
	}
	std::string getDescription() const override {
		return "Decaf coffee";
	}
};
class Espresso : public Beverage { // ��������
public:
	double cost() const override {
		return 3.5;
	}
	std::string getDescription() const override {
		return "Espresso coffee";
	}
};