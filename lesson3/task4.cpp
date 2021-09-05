#include <iostream>

using namespace std;

extern int a, b, c, d;

int main() {

	float result = a * (b + (static_cast<float>(c) / d));
	cout << result << endl;

	return 0;
}