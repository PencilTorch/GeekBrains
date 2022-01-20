#include <iostream>

class Figure {
public:
	virtual float area() = 0;
};

class Parallelogram : public Figure {
public:
	Parallelogram(int x) : x(x), y(0) {}
	Parallelogram(int x, int y) : x(x), y(y) {}
	float area() override
	{
		std::cout << "func by parallelogram\n";
		return static_cast<float>(x * y);
	}
private:
	int x;
	int y;
};

class Rectangle : public Parallelogram {
public:
	Rectangle(int x, int y) : Parallelogram(x, y) {
		this->m_x = x;
		this->m_y = y;
	}
	float area() override
	{
		std::cout << "func by rectangle\n";
		return static_cast<float>(m_x * m_y);
	}
private:
	int m_x;
	int m_y;
};

class Square : public Parallelogram {
public:
	Square(int x) : Parallelogram(x) {
		this->m_x = x;
	}
	float area() override
	{
		std::cout << "func by square\n";
		return static_cast<float>(m_x * m_x);
	}
private:
	int m_x;
};

class Rhombus : public Parallelogram {
public:
	Rhombus(int a, int h) : Parallelogram(a, h) {
		this->m_a = a;
		this->m_h = h;
	}
	float area() override
	{
		std::cout << "func by rhombus\n";
		return static_cast<float>(m_a * m_h);
	}
private:
	int m_a;
	int m_h;
};

class Circle : public Figure {
public:
	Circle(int r) : m_r(r) {}
	float area() override
	{
		std::cout << "func by circle\n";
		return static_cast<float>((m_r * m_r) * PI);
	}
private:
	int m_r;
	const double PI = 3.141592653589793238463;
};

int main() {
	Parallelogram p(3, 5);
	std::cout << p.area() <<std::endl;
	Rectangle rect(4, 6);
	Parallelogram* pPar = &rect;
	std::cout << pPar->area() << std::endl;
	Square square(4);
	pPar = &square;
	std::cout << pPar->area() << std::endl;
	Rhombus rhombus(10, 20);
	pPar = &rhombus;
	std::cout << pPar->area() << std::endl;
	Circle c(2);
	std::cout << c.area();

	return 0;
}
