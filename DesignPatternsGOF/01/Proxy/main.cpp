#include "proxy.h"


int main() {
	proxyAutomat pAuto1("Oktyabrskaya", 1000.);
	pAuto1.addProduct("chocolate Alenka", 100);
	pAuto1.changePrice("chocolate Alenka", 175.90);
	pAuto1.addProduct("chocolate Vdohnovenie", 50);
	pAuto1.changePrice("chocolate Vdohnovenie", 275.39);
	pAuto1.addProduct("chocolate Alpen Gold", 30);
	pAuto1.changePrice("chocolate Alpen Gold", 190.50);
	pAuto1.sellProduct("chocolate Alenka");

	std::cout << pAuto1.allMoneyReport() << std::endl;
	std::cout << pAuto1.getLocationReport() << std::endl;

	return 0;
}