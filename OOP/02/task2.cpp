#include <iostream>
#include <string>


class Fruit {
public:
	Fruit() {
		this->name = "";
		this->color = "";
	}
	void setColor(std::string color) {
		this->color = color;
	}
	std::string getColor() const {
		return color;
	}
	std::string getName() const {
		return name;
	}
protected:
	void setName(std::string name) {
		this->name = name;
	}
private:
	std::string name;
	std::string color;
};

class Apple : public Fruit {
public:
	Apple() {
		setName("apple");
		setColor("green");
	}
	Apple(std::string color) {
		setName("apple");
		setColor(color);
	}
private:

};

class Banana : public Fruit {
public:
	Banana() {
		setName("banana");
		setColor("yellow");
	}
	Banana(std::string color) {
		setName("banana");
		setColor(color);
	}
private:

};

class GrannySmith : public Apple {
public:
	GrannySmith() {
		setName("Granny Smith apple");
		setColor("green");
	}
	GrannySmith(std::string color) {
		setName("Granny Smith apple");
		setColor(color);
	}
private:

};


int main() {

	Apple a("red");
	Banana b;
	GrannySmith c;

	std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
	std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
	std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

	return 0;
}