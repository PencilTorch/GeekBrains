#pragma once
#include <iostream>
#include <Windows.h>


// Abstraction
class Shape {
public:
	virtual void draw() = 0; // low-level
	virtual void resize(double pct) = 0; // high-level
	virtual ~Shape() {}
};

class Rect : public Shape {
public:
	Rect(HBRUSH brush, int x = 0, int y = 0, int width = 0, int height = 0) : _x(x), _y(y), _width(width), _height(height), _brush(brush) {}
	~Rect() { DeleteObject(_brush); }
	void draw() override {
		HWND hwnd = GetConsoleWindow();
		HDC dc = GetDC(hwnd);
		SelectObject(dc, _brush);
		Rectangle(dc, _x, _y, _x + _width, _y + _height);
		ReleaseDC(hwnd, dc);
	}
	void resize(double pct) override {
		_width += _width * (pct / 100);
		_height += _height * (pct / 100);
	}	
private:
	int _x;
	int _y;
	int _width;
	int _height;
	HBRUSH _brush;
};

// Implementor
class DrawingImplementor {
public:
	virtual void drawRectangle(double) = 0;
	virtual ~DrawingImplementor() {
	}
};

class DrawingBrush : public DrawingImplementor {
public:
	~DrawingBrush() { 
		delete _shape;
		DeleteObject(brush);
	}
	void drawRectangle(double size) override {
		brush = CreateSolidBrush(RGB(0, 255, 0));
		_shape = new Rect(brush, 10, 10, (int)size, (int)size);
		_shape->draw();
	}
private:
	Shape* _shape = nullptr;
	HBRUSH brush;
};

class DrawingPencil : public DrawingImplementor {
public:
	~DrawingPencil() { 
		delete _shape;
		DeleteObject(brush);
	}
	void drawRectangle(double size) override {
		brush = CreateHatchBrush(PS_NULL, RGB(255, 0, 0));
		_shape = new Rect(brush, 250, 10, (int)size, (int)size);
		_shape->draw();
	}
private:
	Shape* _shape = nullptr;
	HBRUSH brush;
};
