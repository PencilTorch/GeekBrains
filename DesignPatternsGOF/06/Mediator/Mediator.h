#pragma once
#include <iostream>
#include <vector>

class Calendar {
public:
	bool checkCalendar() {
		return true;
		// ”прощенна€ реализаци€, должен возвращать true, если рабочий день.
	}
};

class Mediator;

class Device {
public:
	Device(Mediator* med = nullptr) : pMediator(med) {}
	virtual void doWork() = 0;
	virtual ~Device() {}
protected:
	Mediator* pMediator;
};

class Mediator {
public:
	Mediator(Calendar* calendar) : _calendar(calendar) {}
	~Mediator() {}
	void Notify(Device* device) {
		for (auto it : _device) {
			if (it == device) {
				if (_calendar->checkCalendar())
					it->doWork();
			}
		}
	}
	void AddDevice(Device* nd) {
		_device.push_back(nd);
	}
private:
	std::vector<Device*> _device;
	Calendar* _calendar;
};

class Coffee : public Device {
public:
	Coffee(Mediator* med = nullptr) : Device(med) { pMediator->Notify(this); }
	void doWork() override {
		std::cout << "Starting coffee" << std::endl;
	}
};

class TeaPot : public Device {
public:
	TeaPot(Mediator* med = nullptr) : Device(med) { pMediator->Notify(this); }
	void doWork() override {
		std::cout << "Starting tea" << std::endl;
	}
};

class Alarm : public Device {
public:
	Alarm(Mediator* med = nullptr) : Device(med) { pMediator->Notify(this); }
	void doWork() override {
		std::cout << "Rise and shine, Mr. Freeman" << std::endl;
	}
};