#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <windows.h>

class Strategy {
public:
	virtual void Divide(std::string&) = 0;
};

class StrategyByScreenWidth : public Strategy {
public:
	StrategyByScreenWidth() {
		//определяем ширину консольного окна
		CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
		GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbiInfo);
		iWidth = csbiInfo.dwSize.X;
	}
	void Divide(std::string& text) override {
		iWidth -= 2; // делаем ширину чуть поуже, чем ширина консольного окна
		size_t i = 0;
		std::string::const_iterator it = text.begin();
		while (it != text.end()) {
			if (i == iWidth) {
				text.insert(it, '\n');
				i = 0;
			}
			++i;
			++it;
		}
	}
private:
	size_t iWidth;
};

class StrategyBySentence : public Strategy {
public:
	StrategyBySentence() {
		tokens = ".?!;";
	}
	void Divide(std::string& text) override {
		for (std::string::const_iterator it = text.begin(); it != text.end(); ++it) {
			if (tokens.find(*it) != std::string::npos) {
				++it;
				text.erase(it);
				text.insert(it, '\n');
			}
		}
	}
private:
	std::string tokens;
};

class StrategyUserWidth : public Strategy {
public:
	StrategyUserWidth(size_t width) : iWidth(width) {}
	void Divide(std::string& text) override {
		size_t i = 0;
		std::string::const_iterator it = text.begin();
		while (it != text.end()) {
			if (i == iWidth) {
				text.insert(it, '\n');
				i = 0;
			}
			++i;
			++it;
		}
	}
private:
	size_t iWidth;
};

class ITextWork {
public:
	virtual ~ITextWork() {}
	virtual void useStrategy() = 0;
	virtual void setStrategy(Strategy*) = 0;
};

class TextEditor : ITextWork {
public:
	TextEditor() : _strategy(nullptr) {}
	TextEditor(const std::string& text) : all_text(text), _strategy(nullptr) {}
	TextEditor(std::ifstream& file) : _strategy(nullptr) {
		std::string line;
		if (file.is_open()) {
			while (getline(file, line))
			{
				all_text += line;
			}
		}
	}
	~TextEditor() {
		delete _strategy;
	}
	void useStrategy() override {
		_strategy->Divide(all_text);
	}
	void setStrategy(Strategy* strategy) override {
		_strategy = strategy;
	}
	void PrintText() const {
		std::cout << all_text << std::endl;
	}
private:
	std::string all_text;
	Strategy* _strategy;
};