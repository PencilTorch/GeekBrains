#pragma once
#include "Beverage.h"

class Decorator : public Beverage {
public:
	Decorator(Beverage* beverage) : _beverage(beverage) {}
	std::string getDescription() const override {
		return _beverage->getDescription();
	}
	double cost() const override {
		return _beverage->cost();
	}
private:
	Beverage* _beverage;
};

class ChocoDecor : public Decorator {
public:
	ChocoDecor(Beverage* bever, double chocoCost = 0.5) : Decorator(bever), _chocoCost(chocoCost) {
		description = ". Beverage with chocolate.\n";
	}
	std::string getDescription() const {
		return Decorator::getDescription() + description;
	}
	double cost() const {
		return Decorator::cost() + _chocoCost;
	}
private:
	double _chocoCost;
	std::string description;
};

class CinnamonDecor : public Decorator {
public:
	CinnamonDecor(Beverage* bever, double cinnamonCost = 0.6) : Decorator(bever), _cinnamonCost(cinnamonCost) {
		description = ". Beverage with cinnamon.\n";
	}
	std::string getDescription() const {
		return Decorator::getDescription() + description;
	}
	double cost() const {
		return Decorator::cost() + _cinnamonCost;
	}
private:
	double _cinnamonCost;
	std::string description;
};

class CreamDecor : public Decorator {
public:
	CreamDecor(Beverage* bever, double creamCost = 0.7) : Decorator(bever), _creamCost(creamCost) {
		description = ". Beverage with whipped cream.\n";
	}
	std::string getDescription() const {
		return Decorator::getDescription() + description;
	}
	double cost() const {
		return Decorator::cost() + _creamCost;
	}
private:
	double _creamCost;
	std::string description;
};

class NoSugarDecor : public Decorator {
public:
	NoSugarDecor(Beverage* bever, double sugarCost = 0.25) : Decorator(bever), _sugarCost(sugarCost) {
		description = ". Beverage without sugar.\n";
	}
	std::string getDescription() const {
		return Decorator::getDescription() + description;
	}
	double cost() const {
		return Decorator::cost() - _sugarCost;
	}
private:
	double _sugarCost;
	std::string description;
};