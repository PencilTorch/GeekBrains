#pragma once
#include <iostream>
#include <vector>

class Menu;
class Ingredient;
class MenuItem;

class IVisitor {
public:
	virtual ~IVisitor(){}
	virtual void visit(Menu& ref) = 0;
	virtual void visit(Ingredient& ref) = 0;
	virtual void visit(MenuItem& ref) = 0;
};

class Food {
public:
	virtual ~Food(){}
	virtual void accept(IVisitor&) = 0;
};

class Menu : public Food {
public:
	void accept(IVisitor& ref) override {
		ref.visit(*this);
	}
	Menu* getState() {
		return this;
	}
};

class Ingredient :public Food {
public:
	void accept(IVisitor& ref) override {
		ref.visit(*this);
	}
	Ingredient* getState() {
		return this;
	}
	std::string _name;
	int _healthRating;
	float _Calories;
	float _Protein;
	float _Carbs;
	float _Fats;
};

class MenuItem : public Menu, public Ingredient {
public:
	MenuItem(const std::string& name, const std::string& description, float price) : name(name), description(description), price(price) {}
	const std::string& getName() const {
		return name;
	}
	const std::string& getDescription() const {
		return description;
	}
	float getPrice() const {
		return price;
	}
	void accept(IVisitor& ref) override {
		ref.visit(*this);
	}
	Ingredient* getState() {
		return this;
	}
private:
	std::string name;
	std::string description;
	float price;
	std::vector<Ingredient*> ingredients;
};

class Client : public IVisitor {
public:
	Client() {
		menu = new Menu;
		ingr = new Ingredient;
	}
	~Client() {
		delete menu;
		delete ingr;
	}
	void visit(Menu& ref) override {
		menu = ref.getState();
	}
	void visit(Ingredient& ref) override {
		ingr = ref.getState();

	}
	void visit(MenuItem& ref) override {
		ingr = ref.getState();
	}
	int getHealthRating() const {
		return ingr->_healthRating;
	}
	float getCalories() const {
		return ingr->_Calories;
	}
	float getProtein() const {
		return ingr->_Protein;
	}
	float getCarbs() const {
		return ingr->_Carbs;
	}
	float getFats() const {
		return ingr->_Fats;
	}
private:
	Menu* menu;
	Ingredient* ingr;
};