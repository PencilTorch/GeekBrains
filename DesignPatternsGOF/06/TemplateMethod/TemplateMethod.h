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

// Растровое изображение
class BitmapImage : public Image {
private:
	void readFile() override {
		readBitmapFile();
	}
	void draw() override {
		for (const auto& it : buffer) {
			it.Draw(); // Рисуем каждый пиксель из буфера
		}
	}
	void final() override {
		std::cout << "Drawing bitmap image complete" << std::endl;
	}
	void readBitmapFile() {
		for (const auto pixel : pixels) {
			buffer.push_back(*pixel); // Имитируем чтение пикселей из файла в буфер
		}
	}
	std::vector<Pixel*> pixels; // это пиксели, которые хранятся в файле
	std::vector<Pixel> buffer; // это пиксели, которые мы читаем для отображение на экране
	};

struct Figure {
	int x;
	int y;
	std::string figure;
	void Draw() const {
		std::cout << "(" << x << ", " << y << ", " << figure << ") ";
	}
	};

// Векторное изображение
class VectorImage : public Image {
private:
	void readFile() override {
		readVectorFile();
	}
	void draw() override {
		for (const auto& it : buffer) {
			it.Draw(); 	// Рисуем каждую фигуру из буфера
		}
	}
	void final() override {
		std::cout << "Drawing vector image complete" << std::endl;
	}
	void readVectorFile() {
		for (const auto figure : figures) {
			buffer.push_back(*figure); 	// Имитируем чтение фигур из файла в буфер
		}
	}
	std::vector<Figure*> figures; // это описание фигур, которые хранятся в файле
	std::vector<Figure> buffer; // это описание фигур, которые мы читаем для отображение на экране
	};