#pragma once
#include <iostream>
#include <vector>

class Image {
public:
	virtual ~Image() {}
	void drawFigure(const std::string& filename) {
		openFile(filename);
		readFile();
		draw();
		final();
	}
protected:
	void openFile(const std::string& filename) {
		std::cout << "Open file " << filename << std::endl;
	}
	virtual void readFile() = 0;
	virtual void draw() = 0;
	virtual void final() = 0;
};

struct Pixel {
	int x;
	int y;
	std::string color;
	void Draw() const {
		std::cout << "(" << x << ", " << y << ", " << color << ") ";
	}
	};

// ��������� �����������
class BitmapImage : public Image {
private:
	void readFile() override {
		readBitmapFile();
	}
	void draw() override {
		for (const auto& it : buffer) {
			it.Draw(); // ������ ������ ������� �� ������
		}
	}
	void final() override {
		std::cout << "Drawing bitmap image complete" << std::endl;
	}
	void readBitmapFile() {
		for (const auto pixel : pixels) {
			buffer.push_back(*pixel); // ��������� ������ �������� �� ����� � �����
		}
	}
	std::vector<Pixel*> pixels; // ��� �������, ������� �������� � �����
	std::vector<Pixel> buffer; // ��� �������, ������� �� ������ ��� ����������� �� ������
	};

struct Figure {
	int x;
	int y;
	std::string figure;
	void Draw() const {
		std::cout << "(" << x << ", " << y << ", " << figure << ") ";
	}
	};

// ��������� �����������
class VectorImage : public Image {
private:
	void readFile() override {
		readVectorFile();
	}
	void draw() override {
		for (const auto& it : buffer) {
			it.Draw(); 	// ������ ������ ������ �� ������
		}
	}
	void final() override {
		std::cout << "Drawing vector image complete" << std::endl;
	}
	void readVectorFile() {
		for (const auto figure : figures) {
			buffer.push_back(*figure); 	// ��������� ������ ����� �� ����� � �����
		}
	}
	std::vector<Figure*> figures; // ��� �������� �����, ������� �������� � �����
	std::vector<Figure> buffer; // ��� �������� �����, ������� �� ������ ��� ����������� �� ������
	};