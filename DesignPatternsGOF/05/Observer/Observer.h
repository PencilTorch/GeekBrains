#pragma once
#include <iostream>
#include <vector>
#include <string>

class ICitizen {
public:
	virtual ~ICitizen() {}
	virtual void listen(int, std::string) = 0;
};

class IListeners {
public:
	virtual ~IListeners() {}
	virtual void addListener(ICitizen* listener) = 0;
	virtual void delListener(ICitizen* listener) = 0;
};

class Doctor : public ICitizen {
private:
	int hearingPower = 100;
public:
	void listen(int voicePower, std::string notify) override {
		if (voicePower >= hearingPower)
			std::cout << "Doctor: " << notify << std::endl;
	}
};
class Blacksmith : public ICitizen {
private:
	int hearingPower = 30;
public:
	void listen(int voicePower, std::string notify) override {
		if (voicePower >= hearingPower)
			std::cout << "Blacksmith: " << notify << std::endl;
	}
};
class Child : public ICitizen {
private:
	int hearingPower = 50;
public:
	void listen(int voicePower, std::string notify) override {
		if (voicePower >= hearingPower)
			std::cout << "Child: " << notify << std::endl;
	}
};

class Herald : public IListeners {
public:
	Herald() {
		_citizens = { new Doctor, new Child, new Blacksmith };
	}
	~Herald() {
		for (auto& it : _citizens)
			delete it;
	}
	int getVoicePower() const {
		return _voicePower;
	}
	std::string getAnnouncement() const {
		return _announcement;
	}
	void setVoicePower(int vp) {
		_voicePower = vp;
	}
	void setAnnouncement(std::string notify) {
		_announcement = notify;
	}
	void changeAnnouncment() {
		for (const auto citizen : _citizens) {
			citizen->listen(_voicePower, _announcement);
		}
	}
	void addListener(ICitizen* listener) override {
		_citizens.push_back(listener);
	}
	void delListener(ICitizen* listener) override {
		_citizens.erase(remove(_citizens.begin(), _citizens.end(), listener), _citizens.end());
	}
private:
	int _voicePower;
	std::string _announcement;
	std::vector<ICitizen*> _citizens;
};
