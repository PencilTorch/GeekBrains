#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
T Div(T a, T b) {
	if (b == 0) {
		throw invalid_argument("Denominator cannot be zero!");
	}
	return a / b;
} 

int main() {
	try
	{
		cout<< Div(5.0, 0.0);
	}
	catch (const invalid_argument& e)
	{
		cerr << "Error: " << e.what() << endl;
	}


	return 0;
}
