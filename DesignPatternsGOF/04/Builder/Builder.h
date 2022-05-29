#pragma once
#include <iostream>
#include <vector>

class Events {
public:
	virtual void getEvent() = 0;
	virtual ~Events() {};
};
class Hotel : public Events {
public:
	void getEvent() {
		std::cout << "Booking Hotel" << std::endl;
	}
};
class Park : public Events {
public:
	void getEvent() {
		std::cout << "Park visiting" << std::endl;
	}
};

class Food : public Events {
public:
	virtual void getEvent() = 0;
	virtual ~Food() {};
};
class Dinner : public Food {
public:
	Dinner(const std::string& type = "breakfast") : _type(type) {}
	void getEvent() {
		std::cout << "Food " << _type << std::endl;
	};
private:
	std::string _type;
};
class Lunch : public Food {
public:
	Lunch() : _type("lunch") {}
	void getEvent() {
		std::cout << "Food " << _type << std::endl;
	};
private:
	std::string _type;
};
class Breakfast : public Food {
public:
	Breakfast() : _type("breakfast") {}
	void getEvent() {
		std::cout << "Food " << _type << std::endl;
	};
private:
	std::string _type;
};
class Special : public Events {
public:
	virtual void getEvent() = 0;
	virtual ~Special() {};
};
class Skating :public Special {
public:
	Skating(const std::string& type = "skating") : _type(type) {}
	void getEvent() {
		std::cout << _type << std::endl;
	};
private:
	std::string _type;
};
class Circus :public Special {
public:
	Circus(const std::string& type = "circus") : _type(type) {}
	void getEvent() {
		std::cout << _type << std::endl;
	};
private:
	std::string _type;
};

struct Actions {
	void getActions() const {
		for (const auto& it : ve) {
			it->getEvent();
		}
	}
	virtual ~Actions() {
		for (const auto& it : ve) {
			delete it;
		}
	}

	std::vector<Events*> ve;
};

class IBuilder {
public:
	virtual ~IBuilder() { delete pAction; }
	virtual Actions* getAction() { return pAction; }
	virtual void buildHotel() {}
	virtual void buildPark() {}
	virtual void buildDinner(const std::string&) {}
	virtual void buildLunch() {}
	virtual void buildBreakfast() {}
	virtual void buildSkating(const std::string&) {}
	virtual void buildCircus(const std::string&) {}
protected:
	Actions* pAction;
};

class FirstDayActionBuilder : public IBuilder{
public:
	FirstDayActionBuilder() { pAction = new Actions; }
protected:
	void buildHotel() override {
		Events* hotel = new Hotel;
		pAction->ve.push_back(hotel);
	}
	void buildDinner(const std::string& type) override {
		Events* dinner = new Dinner(type);
		pAction->ve.push_back(dinner);
	}
	void buildPark() override {
		Events* park = new Park;
		pAction->ve.push_back(park);
	}
	
};

class SecondDayActionBuilder : public IBuilder {
public:
	SecondDayActionBuilder() { pAction = new Actions; }
protected:
	void buildHotel() override {
		Events* hotel = new Hotel;
		pAction->ve.push_back(hotel);
	}
	void buildPark() override {
		Events* park = new Park;
		pAction->ve.push_back(park);
	}
	void buildBreakfast() override {
		Events* breakfast = new Breakfast;
		pAction->ve.push_back(breakfast);
	}
	void buildDinner(const std::string& type) override {
		Events* dinner = new Dinner(type);
		pAction->ve.push_back(dinner);
	}
	void buildSkating(const std::string& type) override {
		Events* skating = new Skating(type);
		pAction->ve.push_back(skating);
	}
};

class ThirdDayActionBuilder : public IBuilder {
public:
	ThirdDayActionBuilder() { pAction = new Actions; }
protected:
	void buildPark() override {
		Events* park = new Park;
		pAction->ve.push_back(park);
	}
	void buildBreakfast() override {
		Events* breakfast = new Breakfast;
		pAction->ve.push_back(breakfast);
	}
	void buildLunch() override {
		Events* lunch = new Lunch;
		pAction->ve.push_back(lunch);
	}
	void buildCircus(const std::string& type) {
		Events* circus = new Circus(type);
		pAction->ve.push_back(circus);
	}
};

class Vacation {
public:
	Actions* createActionsDay(IBuilder& builder) {
		builder.buildHotel();
		builder.buildPark();
		builder.buildBreakfast();
		builder.buildLunch();
		builder.buildDinner("dinner");
		builder.buildSkating("skate");
		builder.buildCircus("circus");
		return builder.getAction();
	}
};
