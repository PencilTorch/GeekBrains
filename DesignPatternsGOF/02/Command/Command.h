#pragma once
#include <iostream>
#include <vector>
#include "Light.h"

std::ostream& operator<<(std::ostream& os, const Colors& clr) {
	switch (clr) {
	case Colors::RED:		return  os << "RED\n";
	case Colors::ORANGE:	return  os << "ORANGE\n";
	case Colors::YELLOW:    return  os << "YELLOW\n";
	case Colors::GREEN:     return  os << "GREEN\n";
	case Colors::CYAN:		return  os << "CYAN\n";
	case Colors::BLUE:		return  os << "BLUE\n";
	case Colors::VIOLET:    return  os << "VIOLET\n";
	case Colors::WHITE:     return  os << "WHITE\n";
	default:
		return  os << "Invalid color!\n";
	}
}

class Command {
public:
	Command() : _light(nullptr) {}
	virtual ~Command() {}

	virtual void turnOn() = 0;
	virtual void turnOff() = 0;
	virtual void setColor(Colors color) = 0;
	virtual Colors getColors() const = 0;
	virtual bool getState() const = 0;
	void setLight(Light* light) {
		_light = light;
	}
protected:
	Light* _light;
};

class WorkCommand : public Command {
public:
	WorkCommand(bool state, Colors color) : _state(state), _color(color) {}
	~WorkCommand() override {}
	void turnOn() override {
		_light->On();
		_state = true;
	}
	void turnOff() override {
		_light->Off();
		_state = false;
	}
	void setColor(Colors color) override {
		_light->changeColor(color);
		_color = color;
	}
	Colors getColors() const override {
		return _color;
	}
	bool getState() const override {
		return _state;
	}
private:
	bool _state;
	Colors _color;
};

class Invoker {
public:
	Invoker() : pCommand(nullptr) { }
	~Invoker() {
		for (Command* ptr : DoneCommands)
			delete ptr;
	}

	void onWard(bool state, Colors color = Colors::WHITE) {
		pCommand = new WorkCommand(state, color);
		pCommand->setLight(&_light);
		if (state)
			pCommand->turnOn();
		else
			pCommand->turnOff();
		pCommand->setColor(color);
		DoneCommands.push_back(pCommand);
	}
	void backWard() {
		if (DoneCommands.size() == 0) {
			std::cout << "There is nothing for back!\n";
		}
		else {
			pCommand = DoneCommands.back();
			DoneCommands.pop_back();
			delete pCommand;
			if (DoneCommands.size() != 0) {
				pCommand = DoneCommands.back();
				_light.changeColor(pCommand->getColors());
				if (pCommand->getState())
					_light.On();
				else
					_light.Off();
			}
			else {
				_light.Off();
				_light.changeColor(Colors::WHITE);
			}
		}
	}
	void ShowState() {
		if (_light.getState()) {
			std::cout << "ON ";
			std::cout << pCommand->getColors();
		}
		else
			std::cout << "OFF\n";
	}
private:
	std::vector<Command*> DoneCommands;
	Light _light;
	Command* pCommand;
};