#pragma once
#include <iostream>

class IShape {
public:
	virtual void scale(double scale_percentage) = 0; // Масштабируем фигуру
		virtual void rotate(double angle) = 0; 	// Поворачиваем фигуру
		virtual void flip() = 0; // Отражаем фигуру
};
class Figure : IShape {
public:
	Figure(int width, int height) : width(width), height(height),
		angle(0.0), isFlipped(false) {}
	void scale(double scale_percentage) override {
		width *= scale_percentage;
		height *= scale_percentage;
	}
	void rotate(double angle) override {
		angle += angle;
	}
	void flip() override {
		isFlipped = !isFlipped;
	}
private:
	int width;
	int height;
	double angle;
	bool isFlipped;
};

class IText {
	virtual void newSize(int size) = 0; // Изменяем размер шрифта текста
	virtual void rotate(double angle) = 0; // Поворачиваем текст
	virtual void reverse() = 0; // Изменяем направление текста
};
class Text : IText {
public:
	Text(const std::string text, int size, double angle, bool isReversed)
		: text(text), size(size), angle(0.0), isReversed(false) {}
	void newSize(int newSize) override {
		size = newSize;
	}
	void rotate(double newAngle) override {
		angle = newAngle;
	}
	void reverse() override {
		for (int i = 0; i < text.size() / 2; ++i) {
			char c = text[i];
			text[i] = text[text.size() - 1 - i];
			text[text.size() - 1 - i] = c;
		}
	}
private:
	int size;
	double angle;
	bool isReversed;
	std::string text;
};

class TextAdapter : public Figure {

public:
	TextAdapter(const Text& text) : _text(text) {}

	void scale(double scale_percentage) override {
		_text.newSize(static_cast<int>(scale_percentage));
	}
	void rotate(double angle) {
		_text.rotate(angle);
	}
	void flip() override {
		_text.reverse();
	}
private:
	Text _text;
};