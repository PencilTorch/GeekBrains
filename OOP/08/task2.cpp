#include <iostream>

using namespace std;

class Ex {
public:
	Ex(float x) {
		this->x = x;
	}
	float getError() const {
		return x;
	}
private:
	float x;
};

class Bar {
public:
	Bar(float y = 0) {
		this->y = y;
	}
	void set(float a) {
		if (y + a > 100) {
			throw Ex(a * y);
		}
		else
			y = a;
	}
private:
	float y;
};


int main() {
	Bar bar;
	int n;
	cin >> n;
	try
	{
		while (n != 0) {
			bar.set(static_cast<float>(n));
			cin >> n;
		}
	}
	catch (const Ex& ex)
	{
		cerr << "Error: " << ex.getError() << endl;
	}


	return 0;
}

