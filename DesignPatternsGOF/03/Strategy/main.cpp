#include "Strategy.h"

int main() {
	setlocale(LC_ALL, "Russian");
	std::string str = "В языке C++ поддержка строк осуществляется двумя способами. \
Первый состоит в использовании символьного массива, завершающегося нулевым символом? \
Такой массив иногда называется С-строкой. Второй способ подразумевает работу с объектом класса типа basic_string!";

	std::cout << "Strategy By Screen Width:\n";
	TextEditor txtEd1(str);
	Strategy* strateg = new StrategyByScreenWidth;
	txtEd1.setStrategy(strateg);
	txtEd1.useStrategy();
	txtEd1.PrintText();
	std::cout << std::endl;

	std::cout << "Strategy By Sentence:\n";
	TextEditor txtEd2(str);
	strateg = new StrategyBySentence;
	txtEd2.setStrategy(strateg);
	txtEd2.useStrategy();
	txtEd2.PrintText();

	std::cout << "Strategy User Width:\n";
	TextEditor txtEd3(str);
	strateg = new StrategyUserWidth(30);
	txtEd3.setStrategy(strateg);
	txtEd3.useStrategy();
	txtEd3.PrintText();

	return 0;
}