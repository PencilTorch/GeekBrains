#pragma once
#include <iostream>
#include <vector>

class IFood {
public:
	virtual ~IFood() {}
	virtual float getPrice() const = 0;
	virtual std::string getName() const = 0;
};

class Pancake : public IFood {
public:
	Pancake(const std::string& name, float price) : name(name), price(price) {}
	float getPrice() const override {
		return price;
	}
	std::string getName() const override {
		return name;
	}
protected:
	std::string name;
	float price;
};
class MorningPancake : public Pancake {
public:
	MorningPancake() : Pancake("Morning pancake", 240.0f) {}
};
class LunchPancake : public Pancake {
public:
	LunchPancake() : Pancake("Lunch pancake", 280.0f) {}
};
class MexicanPancake : public Pancake {
public:
	MexicanPancake() : Pancake("Mexican pancake", 270.0f) {}
};
class PotatoPancake : public Pancake {
public:
	PotatoPancake() : Pancake("Potato pancake", 210.0f) {}
};
class MushroomPancake : public Pancake {
public:
	MushroomPancake() : Pancake("Mushroom pancake", 220.0f) {}
};
class FalafelPancake : public Pancake {
public:
	FalafelPancake() : Pancake("Falafel pancake", 270.0f) {}
};
class ChocolatePancake : public Pancake {
public:
	ChocolatePancake() : Pancake("Chocolate pancake", 260.0f) {}
};
class BananaPancake : public Pancake {
public:
	BananaPancake() : Pancake("Banana pancake", 260.0f) {}
};
class JamPancake : public Pancake {
public:
	JamPancake() : Pancake("Jam pancake", 190.0f) {}
};

class Icecream : public IFood {
public:
	Icecream() {}
	Icecream(const std::string& name, float price) : name(name), price(price) {}
	float getPrice() const override {
		return price;
	}
	std::string getName() const override {
		return name;
	}
private:
	std::string name;
	float price;
};
class BananaSplit : public Icecream {
public:
	BananaSplit() : Icecream("Banana Split", 260) {}
private:
	std::string name;
	float price;
};
class BerryScream : public Icecream {
public:
	BerryScream() : Icecream("Berry ice cream", 260) {}
private:
	std::string name;
	float price;
};
class HotBrauni : public Icecream {
public:
	HotBrauni() : Icecream("Hot Brauni", 310) {}
private:
	std::string name;
	float price;
};
class TuttiFruity : public Icecream {
public:
	TuttiFruity() : Icecream("Tutti Fruity", 240) {}
private:
	std::string name;
	float price;
};
class Vanilla : public Icecream {
public:
	Vanilla() : Icecream("Vanilla ice cream", 180) {}
private:
	std::string name;
	float price;
};
class Pistachio : public Icecream {
public:
	Pistachio() : Icecream("Pistachio ice cream", 230) {}
private:
	std::string name;
	float price;
};

class Beverage : public IFood {
public:
	Beverage() {}
	Beverage(const std::string& name, float price) : name(name), price(price) {}
	float getPrice() const override {
		return price;
	}
	std::string getName() const override {
		return name;
	}
private:
	std::string name;
	float price;
};
class Pepsi : public Beverage {
public:
	Pepsi() : Beverage("Pepsi", 120) {}
private:
	std::string name;
	float price;
};
class Coffee : public Beverage {
public:
	Coffee() : Beverage("Coffee", 80) {}
private:
	std::string name;
	float price;
};
class Tea : public Beverage {
public:
	Tea() : Beverage("Tea", 50) {}
private:
	std::string name;
	float price;
};

class ComboFood : public IFood {
public:
	virtual ~ComboFood() {
		for (auto& it : _combofood) {
			delete it;
		}
	}
	float getPrice() const override {
		float total = 0;
		for (auto& it : _combofood) {
			total += it->getPrice();
		}
		return total;
	}
	std::string getName() const override {
		std::string menu = "";
		for (auto& it : _combofood) {
			menu += (it->getName() + " \n");
		}
		return menu;
	}
	void addFood(IFood* food) {
		_combofood.push_back(food);
	}
private:
	std::vector<IFood*> _combofood;
};

ComboFood* MorningMenu() {
	ComboFood* menu = new ComboFood;
	menu->addFood(new MorningPancake);
	menu->addFood(new BananaSplit);
	menu->addFood(new Coffee);
	return menu;
}

ComboFood* LunchMenu() {
	ComboFood* menu = new ComboFood;
	menu->addFood(new LunchPancake);
	menu->addFood(new HotBrauni);
	menu->addFood(new Pepsi);
	return menu;
}

ComboFood* VeganMenu() {
	ComboFood* menu = new ComboFood;
	menu->addFood(new FalafelPancake);
	menu->addFood(new Pistachio);
	menu->addFood(new Tea);
	return menu;
}