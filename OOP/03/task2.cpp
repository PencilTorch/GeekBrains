#include <iostream>
#include <string>

class Car {
public:
	Car(std::string &company, std::string& model) {
		std::cout << "constructor Car" << std::endl;
		this->company = company;
		this->model = model;
		getCarInfo();
	}
	void getCarInfo() const {
		std::cout << company << ", " << model << std::endl;
	}
private:
	std::string company;
	std::string model;
};

class PassengerCar : public Car {
public:
	PassengerCar(std::string& company, std::string& model) : Car(company, model) {
		std::cout << "constructor PassengerCar" << std::endl;
	}
private:
	std::string company;
	std::string model;
};

class Bus : public Car {
public:
	Bus(std::string& company, std::string& model) : Car(company, model) {
		std::cout << "constructor Bus" << std::endl;
	}
private:
	std::string company;
	std::string model;
};

class Minivan : public PassengerCar, public Bus {
public:
	Minivan(std::string& company, std::string& model) : PassengerCar(company, model), Bus(company, model) {
		std::cout << "constructor Minivan" << std::endl;
	}
private:
	std::string company;
	std::string model;
};

int main() {
	std::string company1 = "Ford";
	std::string model1 = "focus";
	std::string company2 = "Renault";
	std::string model2 = "logan";
	std::string company3 = "Ikarus";
	std::string model3 = "Ikarus-E91";
	std::string company4 = "Volkswagen";
	std::string model4 = "Caravelle";

	Car car(company1, model1);
	std::cout << "\n";
	PassengerCar pass(company2, model2);
	std::cout << "\n";
	Bus bus(company3, model3);
	std::cout << "\n";
	Minivan mv(company4, model4);

	return 0;
}
