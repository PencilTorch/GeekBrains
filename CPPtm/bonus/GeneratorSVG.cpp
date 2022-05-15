#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>

enum class Colors { Black, Brown, Red, Yellow, Lime, Green, Blue, Purple, Gray, White };

struct RGB {
	RGB(unsigned short R = 0, unsigned short G = 0, unsigned short B = 0) {
		r = static_cast<char>(R);
		g = static_cast<char>(G);
		b = static_cast<char>(B);
	}
	RGB& operator=(const RGB& other) {
		r = other.r;
		g = other.g;
		b = other.b;
		return *this;
	}
	bool operator==(const RGB& other) {
		return (r == other.r && g == other.g && b == other.b);
	}
	unsigned char r;
	unsigned char g;
	unsigned char b;
};

class Color {
public:
	template <typename T>
	Color(const T& _color) {
		if (mPalitra.empty()) fillPalitra();
		AddColor(_color);
	}
	std::string ShowColor() {
		if (!color.empty()) {
			return color;
		}
		else if (rgb.r != 0 && rgb.g != 0 && rgb.b != 0) {
			return "Rgb(" + std::to_string((int)rgb.r) + ", " + std::to_string((int)rgb.g) + ", " + std::to_string((int)rgb.b) + ")";
		}
		else
			return "none";
	}
private:
	RGB rgb;
	std::string color;
	std::map<std::string, std::pair<Colors, RGB>> mPalitra;
	void fillPalitra() {
		mPalitra["black"] = { {Colors::Black}, { 0, 0, 0 } };
		mPalitra["brown"] = { {Colors::Brown}, { 165, 42, 42 } };
		mPalitra["red"] = { {Colors::Red}, { 255, 0, 0 } };
		mPalitra["yellow"] = { {Colors::Yellow}, { 255, 255, 0 } };
		mPalitra["lime"] = { {Colors::Lime}, { 204, 255, 0 } };
		mPalitra["green"] = { {Colors::Green}, { 0, 255, 0 } };
		mPalitra["blue"] = { {Colors::Blue}, { 0, 0, 255 } };
		mPalitra["purple"] = { {Colors::Purple}, { 160, 32, 240 } };
		mPalitra["gray"] = { {Colors::Gray}, { 190, 190, 190 } };
		mPalitra["white"] = { {Colors::White}, { 255, 255, 255 } };
	}
	void AddColor(const std::string& sc) {
		const auto it = mPalitra.find(sc);
		if (it != mPalitra.end())
			color = sc;
		else
			color = "none";
	}
	void AddColor(const Colors& Cc) {
		for (const auto& it : mPalitra) {
			if (it.second.first == Cc) {
				color = it.first;
				break;
			}
		}
		if (color.empty())
			color = "none";
	}
	void AddColor(const RGB& _rgb) {
		for (auto& it : mPalitra) {
			if (it.second.second == _rgb) {
				color = it.first;
				break;
			}
		}
		if (color.empty()) {
			rgb = _rgb;
		}
	}
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

//базовый абстрактный класс
class Figure {
public:
	Figure() {
		pColor = nullptr;
		thick = 1;
	}
	~Figure() {
		if (pColor != nullptr) {
			delete pColor;
			pColor = nullptr;
		}
	}
	template <typename T>
	void SetStrokeColor(const T& sc) {
		pColor = new Color(sc);
	}
	void SetStrokeWidth(const size_t w) {
		thick = w;
	}
	virtual std::string Show_Info() = 0;
protected:
	Color* pColor;
	size_t thick;
};

class Figure2D : public Figure {
public:
	Figure2D() {
		pFillColor = nullptr;;
	}
	~Figure2D() {
		if (pFillColor != nullptr) {
			delete pFillColor;
			pFillColor = nullptr;
		}
	}
	template <typename T>
	void SetFillColor(const T& fc) {
		pFillColor = new Color(fc);
	}
	virtual std::string Show_Info() = 0;
protected:
	Color* pFillColor;
};

class Line : public Figure {
public:
	Line(const Point& _fst = 0, const Point& _snd = 0) : fst(_fst), snd(_snd) {}
	void setFirstPoint(const int _x, const int _y) {
		fst.x = _x;
		fst.y = _y;
	}
	void setFirstPoint(const Point& fp) {
		fst = fp;
	}
	void setSecondPoint(const int _x, const int _y) {
		snd.x = _x;
		snd.y = _y;
	}
	void setSecondPoint(const Point& sp) {
		snd = sp;
	}
	Line& operator=(const Line& other) {
		fst = other.fst;
		snd = other.snd;
		return *this;
	}
	std::string Show_Info() {
		std::string result = "<line x1=\"" + std::to_string(fst.x);
		result += "\" y1=\"" + std::to_string(fst.y);
		result += "\" x2=\"" + std::to_string(snd.x);
		result += "\" y2=\"" + std::to_string(snd.y);
		result += "\" stroke-width=\"" + std::to_string(thick);
		if (pColor) result += "\" stroke=\"" + pColor->ShowColor() + "\"/>\n";
		else result += "\" stroke=\"none\"/>\n";
		return result;
	}
private:
	Point fst;
	Point snd;
};

class Rect : public Figure2D {
public:
	Rect() : lhp(0), width(0), height(0) {}
	Rect(const Point& _lnt, const size_t w, const size_t h, const size_t _thick) : lhp(_lnt), width(w), height(h) {
		thick = _thick;
	}
	void SetPoint(const int _x, const int _y) {
		lhp.x = _x;
		lhp.y = _y;
	}
	void SetPoint(const Point& other) {
		lhp = other;
	}
	void SetWidth(const size_t w) {
		width = w;
	}
	void SetHeight(const size_t h) {
		height = h;
	}
	std::string Show_Info() override {
		std::string str = "<rect x=\"" + std::to_string(lhp.x);
		str += "\" y=\"" + std::to_string(lhp.y);
		str += "\" width=\"" + std::to_string(width);
		str += "\" height=\"" + std::to_string(height);
		if (pFillColor) str += "\" fill=\"" + pFillColor->ShowColor();
		else str += "\" fill=\"none\"";
		str += "\" stroke-width=\"" + std::to_string(thick);
		if (pColor) str += "\" stroke=\"" + pColor->ShowColor() + "\"/>\n";
		else str += "\" stroke=\"none\"/>\n";
		return str;
	}
private:
	Point lhp;
	size_t width;
	size_t height;
};

class Polygon : public Figure2D {
public:
	void AddPoint(const Point& p) {
		points.push_back(p);
	}
	void AddPoint(const int _x, const int _y) {
		points.push_back(Point(_x, _y));
	}
	std::string Show_Info() override {
		std::string str = "<polygon points=\"";
		for (auto it : points)
			str += std::to_string(it.x) + "," + std::to_string(it.y) + " ";
		if (pFillColor) str += "\" fill=\"" + pFillColor->ShowColor();
		else str += "\" fill=\"none\"";
		str += "\" stroke-width=\"" + std::to_string(thick);
		if (pColor) str += "\" stroke=\"" + pColor->ShowColor() + "\"/>\n";
		else str += "\" stroke=\"none\"/>\n";
		return str;
	}
protected:
	std::vector<Point> points;
};

class Polyline : public Polygon {
public:
	std::string Show_Info() override {
		std::string str = "<polyline points=\"";
		for (auto it : points)
			str += std::to_string(it.x) + "," + std::to_string(it.y) + " ";
		if (pFillColor) str += "\" fill=\"" + pFillColor->ShowColor();
		else str += "\" fill=\"none\"";
		str += "\" stroke-width=\"" + std::to_string(thick);
		if (pColor) str += "\" stroke=\"" + pColor->ShowColor() + "\"/>\n";
		else str += "\" stroke=\"none\"/>\n";
		return str;
	}
};

class Circle : public Figure2D {
public:
	Circle(const Point& c = 0, const size_t r = 0) : center(c), rx(r) {}
	void SetCenter(const int _x, const int _y) {
		center.x = _x;
		center.y = _y;
	}
	void SetCenter(const Point& p) {
		center = p;
	}
	void SetRadius(const size_t r) {
		rx = r;
	}
	std::string Show_Info() override {
		std::string str = "<circle cx=\"" + std::to_string(center.x);
		str += "\" cy=\"" + std::to_string(center.y);
		str += "\" r=\"" + std::to_string(rx);
		if (pFillColor) str += "\" fill=\"" + pFillColor->ShowColor();
		else str += "\" fill=\"none\"";
		str += "\" stroke-width=\"" + std::to_string(thick);
		if (pColor) str += "\" stroke=\"" + pColor->ShowColor() + "\"/>\n";
		else str += "\" stroke=\"none\"/>\n";
		return str;
	}
protected:
	Point center;
	size_t rx;
};

class Ellipse : public Circle {
public:
	Ellipse(const Point& c = 0, const size_t _rx = 0, const size_t _ry = 0) : ry(_ry) {}
	void SetRadius(const size_t _rx, const size_t _ry) {
		rx = _rx;
		ry = _ry;
	}
	std::string Show_Info() override {
		std::string str = "<ellipse cx=\"" + std::to_string(center.x);
		str += "\" cy=\"" + std::to_string(center.y);
		str += "\" rx=\"" + std::to_string(rx);
		str += "\" ry=\"" + std::to_string(ry);
		if (pFillColor) str += "\" fill=\"" + pFillColor->ShowColor();
		else str += "\" fill=\"none\"";
		str += "\" stroke-width=\"" + std::to_string(thick);
		if (pColor) str += "\" stroke=\"" + pColor->ShowColor() + "\"/>\n";
		else str += "\" stroke=\"none\"/>\n";
		return str;
	}
private:
	size_t ry;
};

class Text : public Figure2D {
public:
	Text() : begin_text(0), offset_text(0), font_family("Arial"), font_size(10), text_anchor("") {}
	void SetPoint(const int _x, const int _y) {
		begin_text.x = _x;
		begin_text.y = _y;
	}
	void SetPoint(const Point& p) {
		begin_text = p;
	}
	void SetOffset(const int _x, const int _y) {
		offset_text.x = _x;
		offset_text.y = _y;
	}
	void SetOffset(const Point& p) {
		offset_text = p;
	}
	void SetFontSize(const int _size) {
		font_size = _size;
	}
	void SetTextAnchor(const std::string& ta) {
		text_anchor = ta;
	}
	void SetFontFamily(const std::string ff) {
		font_family = ff;
	}
	void SetData(const std::string& _data_text) {
		data_text = _data_text;
	}
	std::string Show_Info() override {
		std::string str = "<text x=\"" + std::to_string(begin_text.x);
		str += "\" y=\"" + std::to_string(begin_text.y);
		if (offset_text.x != 0) str += "\" dx=\"" + std::to_string(offset_text.x);
		if (offset_text.y != 0) str += "\" dy=\"" + std::to_string(offset_text.y);
		str += "\" font-size=\"" + std::to_string(font_size);
		str += "\" font-family=\"" + font_family;
		if (!text_anchor.empty()) str += "\" text-anchor=\"" + text_anchor;
		if (pFillColor) str += "\" fill=\"" + pFillColor->ShowColor();
		else str += "\" fill=\"none\"";
		str += "\" stroke-width=\"" + std::to_string(thick);
		if (pColor) str += "\" stroke=\"" + pColor->ShowColor();
		else str += "\" stroke=\"none\">";
		str += data_text + "</text>\n";
		return str;
	}
private:
	Point begin_text;
	Point offset_text;
	std::string text_anchor;
	std::string data_text;
	std::string font_family;
	int font_size;
};

class GeneratorSVG {
public:
	template <typename T>
	void Add(T& _obg) {
		obg.push_back(_obg.Show_Info());
	}
	std::string Generate() {
		std::string b = "<svg version=\"1.1\" baseProfile=\"full\" encoding=\"UTF-8\" ";
		b += "xmlns=\"http://www.w3.org/2000/svg\">\n";
		for (auto it : obg)
			b += it;
		return b + "</svg>";
	}
	void MakeFile(const std::string& path) {
		std::ofstream fout(path);
		if (fout.is_open()) {
			fout << Generate();
		}
		else
			std::cout << "File " + path + "don't create!\n";
		fout.close();
	}
private:
	std::vector<std::string> obg;
};

int  main() {
	GeneratorSVG svg;

	Line line(Point(10, 30), Point(30, 40));
	line.SetStrokeColor(RGB(140, 198, 63));
	line.SetStrokeWidth(2);
	svg.Add(line);

	Rect rect;
	rect.SetPoint(80, 70);
	rect.SetWidth(50);
	rect.SetHeight(60);
	rect.SetStrokeColor(RGB(0, 0, 255));
	rect.SetStrokeWidth(3);
	rect.SetFillColor("yellow");
	svg.Add(rect);

	Circle circle;
	circle.SetCenter(150, 20);
	circle.SetRadius(10);
	circle.SetFillColor("white");
	svg.Add(circle);

	Text text;
	text.SetPoint(10, 200);
	text.SetOffset(10, -10);
	text.SetFontSize(16);
	text.SetFontFamily("Arial");
	text.SetFillColor("black");
	text.SetData("Hello world");
	svg.Add(text);

	Ellipse ellipse;
	ellipse.SetCenter(160, 70);
	ellipse.SetRadius(40, 30);
	ellipse.SetFillColor(Colors::Red);
	ellipse.SetStrokeColor("green");
	ellipse.SetStrokeWidth(3);
	svg.Add(ellipse);

	Polygon polig1;
	polig1.AddPoint(350, 75);
	polig1.AddPoint(379, 161);
	polig1.AddPoint(469, 161);
	polig1.AddPoint(397, 215);
	polig1.AddPoint(423, 301);
	polig1.AddPoint(350, 250);
	polig1.AddPoint(277, 301);
	polig1.AddPoint(303, 215);
	polig1.AddPoint(231, 161);
	polig1.AddPoint(321, 161);
	polig1.SetFillColor("red");
	polig1.SetStrokeColor(Colors::Blue);
	polig1.SetStrokeWidth(10);
	svg.Add(polig1);

	Polygon polig2;
	polig2.AddPoint(850, 75);
	polig2.AddPoint(958, 137);
	polig2.AddPoint(958, 262);
	polig2.AddPoint(850, 325);
	polig2.AddPoint(742, 262);
	polig2.AddPoint(742, 137);
	polig2.SetFillColor("lime");
	polig2.SetStrokeColor("blue");
	polig2.SetStrokeWidth(10);
	svg.Add(polig2);

	Polyline pl;
	pl.AddPoint(50, 80);
	pl.AddPoint(140, 80);
	pl.AddPoint(80, 100);
	pl.AddPoint(180, 100);
	pl.AddPoint(160, 85);
	pl.AddPoint(160, 115);
	pl.AddPoint(180, 100);
	pl.SetFillColor(Colors::Gray);
	pl.SetStrokeColor(Colors::Purple);
	pl.SetStrokeWidth(3);
	svg.Add(pl);
	
	svg.MakeFile("file.svg");
	std::string result = svg.Generate();
	std::cout << result;

	return 0;
}
