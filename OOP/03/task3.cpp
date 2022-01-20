#include <iostream>

class Fraction {
public:
	Fraction(int num = 0, int den = 1) {
		numerator = num;
		(den > 0) ? denominator = den : denominator = 1;
	}
	Fraction operator-() const {
		return Fraction(-(this->numerator), this->denominator);
	}
	Fraction operator*(Fraction &other) const {
		return Fraction(this->numerator * other.numerator, this->denominator * other.denominator);
	}
	Fraction operator/(Fraction &other) const {
		return Fraction(this->numerator * other.denominator, this->denominator * other.numerator);
	}
	Fraction& operator=(Fraction const& other) {
		this->numerator = other.getNumerator();
		this->denominator = other.getDenominator();
		return *this;
	}
	void operator()(int const num, int const den) {
		this->numerator = num;
		this->denominator = den;
	}
	int getNumerator() const {
		return numerator;
	}
	int getDenominator() const {
		return denominator;
	}
	void printFraction() {
		std::cout << this->numerator << " / " << this->denominator << std::endl;
	}
private:
	int numerator;
	int denominator;
};

int getNOD(int den1, int den2) {
	int nok = den1 * den2;
	while (den1 > 0 && den2 > 0)
		(den1 > den2) ? den1 %= den2 : den2 %= den1;	
	return nok / (den1 + den2);
}
Fraction reduse(Fraction const& fraction, int const gcd) {
	int num = fraction.getNumerator();
	int den = fraction.getDenominator();
	num *= gcd / den;
	den = gcd;
	return Fraction(num, den);
}
Fraction operator+(Fraction const& first, Fraction const& second) {
	if (first.getDenominator() != second.getDenominator()) {
		int gcd = getNOD(first.getDenominator(), second.getDenominator());
		Fraction t1 = reduse(first, gcd);
		Fraction t2 = reduse(second, gcd);
		return Fraction(t1.getNumerator() + t2.getNumerator(), gcd);
	}
	return Fraction(first.getNumerator() + second.getNumerator(), second.getDenominator());
}

Fraction operator-(Fraction const& first, Fraction const& second) {
	if (first.getDenominator() != second.getDenominator()) {
		int gcd = getNOD(first.getDenominator(), second.getDenominator());
		Fraction t1 = reduse(first, gcd);
		Fraction t2 = reduse(second, gcd);
		return Fraction(t1.getNumerator() - t2.getNumerator(), gcd);
	}
	return Fraction(first.getNumerator() - second.getNumerator(), second.getDenominator());
}

bool operator==(Fraction const& first, Fraction const& second) {
	if (first.getDenominator() != second.getDenominator()) {
		int gcd = getNOD(first.getDenominator(), second.getDenominator());
		Fraction t1 = reduse(first, gcd);
		Fraction t2 = reduse(second, gcd);
		if (t1.getNumerator() == t2.getNumerator())
			return true;
		else
			return false;
	}
	return first.getNumerator() == second.getNumerator();
}

bool operator!=(Fraction const& first, Fraction const& second) {
	return !(first == second);
}

bool operator<(Fraction const& first, Fraction const& second) {
	if (first.getDenominator() != second.getDenominator()) {
		int gcd = getNOD(first.getDenominator(), second.getDenominator());
		Fraction t1 = reduse(first, gcd);
		Fraction t2 = reduse(second, gcd);
		if (t1.getNumerator() < t2.getNumerator())
			return true;
		else
			return false;
	}
	return first.getNumerator() < second.getNumerator();
}

bool operator>(Fraction const& first, Fraction const& second) {
	return second < first;
}

bool operator<=(Fraction const& first, Fraction const& second) {
	if (first.getDenominator() != second.getDenominator()) {
		int gcd = getNOD(first.getDenominator(), second.getDenominator());
		Fraction t1 = reduse(first, gcd);
		Fraction t2 = reduse(second, gcd);
		if (t1.getNumerator() <= t2.getNumerator())
			return true;
		else
			return false;
	}
	return first.getNumerator() <= second.getNumerator();
}

bool operator>=(Fraction const& first, Fraction const& second) {
	return second <= first;
}

int main() {
	Fraction fr1(1, 6);
	Fraction fr2(3, 8);
	Fraction fr3 = fr1 + fr2;
	fr3.printFraction();
	fr1(2, 3);
	fr2(2, 9);
	fr3 = fr1 - fr2;
	fr3.printFraction();
	fr3 = fr1 * fr2;
	fr3.printFraction();
	fr3 = fr1 / fr2;
	fr3.printFraction();
	fr3 = -fr3;
	fr3.printFraction();

	fr1(1, 2);
	fr2(3, 4);
	if (fr1 == fr2)
		std::cout << "true\n";
	else
		std::cout << "false\n";

	if (fr1 < fr2) 
		std::cout << "true\n";
	else 
		std::cout << "false\n";

	if (fr1 >= fr2)
		std::cout << "true\n";
	else
		std::cout << "false\n";


	return 0;
}

