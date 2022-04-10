#include <iostream>
#include <string>
#include <map>

enum class Colors {
	Black,
	Brown,
	Red,
	Yellow,
	Green,
	Blue,
	Purple,
	Gray,
	White
};

struct RGB {
	RGB(const char R = 0, const char G = 0, const char B = 0) : r(R), g(G), b(B) {}
	RGB& operator=(const RGB& other) {
		r = other.r;
		g = other.g;
		b = other.b;
		return *this;
	}
	char r;
	char g;
	char b;
};

class Color {
public:
	Color(const std::string& str) {
		std::map<std::string, RGB> palitra;
		palitra["black"] = { 0, 0, 0 };
		palitra["brown"] = { 165, 42, 42 };
		palitra["red"] = { 255, 0, 0 };
		palitra["yellow"] = { 255, 255, 0 };
		palitra["green"] = { 0, 255, 0 };
		palitra["blue"] = { 0, 0, 255 };
		palitra["purple"] = { 160, 32, 240 };
		palitra["gray"] = { 190, 190, 190 };
		palitra["white"] = { 255, 255, 255 };
		const auto& it = palitra.find(str);
		if (it != palitra.end()) {
			color = it->second;
		}
		else
			color = { 0, 0, 0 };
	}
	Color(Colors clr) {
		switch (clr) {
		case Colors::Black:
			color = { 0, 0, 0 };
			break;
		case Colors::Brown:
			color = { 165, 42, 42 };
			break;
		case Colors::Red:
			color = { 255, 0, 0 };
			break;
		case Colors::Yellow:
			color = { 255, 255, 0 };
			break;
		case Colors::Green:
			color = { 0, 255, 0 };
			break;
		case Colors::Blue:
			color = { 0, 0, 255 };
			break;
		case Colors::Purple:
			color = { 160, 32, 240 };
			break;
		case Colors::Gray:
			color = { 190, 190, 190 };
			break;
		case Colors::White:
			color = { 255, 255, 255 };
			break;
		default:
			color = { 0, 0, 0 };
			break;
		}
	}
	RGB getColor() const {
		return color;
	}
private:
	RGB color;
};

struct Point {
	Point(int X = 0, int Y = 0) : x(X), y(Y) {}
	Point& operator=(const Point& other) {
		x = other.x;
		y = other.y;
		return *this;
	}
	int x;
	int y;
};

class Line {
public:
	Line(const Point& bgn = 0, const Point& end = 0) : fst(bgn), snd(end), thick(1) {}
	void setFirstPoint(const Point& fp) {
		fst = fp;
	}
	void setSecondPoint(const Point& sp) {
		snd = sp;
	}
	void SetStrokeColor(const RGB& rgb) {
		color = rgb;
	}
	void SetStrokeColor(const std::string& str) {
		Color clr(str);
		color = clr.getColor();
	}
	void SetStrokeColor(const Colors clrs) {
		Color clr(clrs);
		color = clr.getColor();
	}
	void SetStrokeWidth(const size_t w) {
		thick = w;
	}
	Line& operator=(const Line& other) {
		fst = other.fst;
		snd = other.snd;
		return *this;
	}
private:
	Point fst;
	Point snd;
	size_t thick; //толщина
	RGB color;
};

class Rect {
public:
	Rect(const Point& pnt = 0, size_t w = 0, size_t h = 0) : lhp(pnt), width(w), height(h), thick(1) {}
	void SetPoint(const int _x, const int _y) {
		lhp.x = _x;
		lhp.y = _y;
	}
	void SetWidth(const size_t w) {
		width = w;
	}
	void SetHeight(const size_t h) {
		height = h;
	}
	void SetStrokeColor(const RGB& clr) {
		color = clr;
	}
	void SetStrokeWidth(const size_t w) {
		thick = w;
	}
	void SetFillColor(const std::string& str) {
		Color clr(str);
		// заполненение цветом
	}
private:
	Point lhp;
	size_t width;
	size_t height;
	RGB color;
	size_t thick;
};

class Circle {
public:
	Circle(const Point& c = 0, const size_t r = 0) : center(c), radius(r) {}
	void SetCenter(const int _x, const int _y) {
		center.x = _x;
		center.y = _y;
	}
	void SetRadius(const size_t r) {
		radius = r;
	}
	void SetFillColor(const std::string str) {
		Color clr(str);
		// заполненение цветом
	}
private:
	Point center;
	size_t radius;
	RGB color;
};


class GeneratorSVG {
public:

private:

};

int  main() {
	Point p1(1, 1);
	Point p2(5, 6);
	Line line(p1, p2);
	line.SetStrokeColor(3);
	

	return 0;
}