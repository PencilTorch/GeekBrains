#include "Iterator.h"
using namespace std;

int main() {
	Simple s1("Ivan", "Sarov", 18);
	Simple s2("Fedor", "Moscow", 28);
	Simple s3("Anna", "Tver", 25);
	VectorCollection vs;
	vs.addSimple(s1);
	vs.addSimple(s2);
	vs.addSimple(s3);
	std::cout << "Vector Iterator:\n";
	IIterator* ivs = vs.createIterator();
	while (ivs->hasNext()) {
		ivs->next().printData();
	}
	while (ivs->hasPrev()) {
		ivs->prev().printData();
	}
	std::cout << "\nList Iterator:\n";
	ListCollection lc;
	lc.addSimple(s1);
	lc.addSimple(s2);
	lc.addSimple(s3);
	IIterator* ilc = lc.createIterator();
	while (ilc->hasNext()) {
		ilc->next().printData();
	}
	while (ilc->hasPrev()) {
		ilc->prev().printData();
	}
	std::cout << "\nDeque Iterator:\n";
	DequeCollection dc;
	dc.addSimple(s1);
	dc.addSimple(s2);
	dc.addSimple(s3);
	IIterator* idc = dc.createIterator();
	while (idc->hasNext()) {
		idc->next().printData();
	}
	while (idc->hasPrev()) {
		idc->prev().printData();
	}
	std::cout << "\nArray Iterator:\n";
	ArrayCollection ac;
	ac.addSimple(s1);
	ac.addSimple(s2);
	ac.addSimple(s3);
	IIterator* iac = ac.createIterator();
	while (iac->hasNext()) {
		iac->next().printData();
	}

	return 0;
}