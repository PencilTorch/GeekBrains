#include <iostream>
#include <string>
#include <ctime>
//Игра будет 1 игрока с компьютером (диллер). В колоде будет 52 карты.

// 4 масти карт
enum Suit { clubs, diamonds, hearts, spades };

// класс одной карты
class Card {
public:
	Card() {
		this->suit = (Suit)0;
		this->valueCard = 0;
	}
	void setCard(int, Suit); // установить значение и масть карты
	void PrintCard(); // показать карту
private:
	Suit suit; // здесь будет масть
	int valueCard; // здесь номинал карты
};

// класс для колоды карт
class DeckCards {
public:
	DeckCards(){
		cards = new Card[size];

	}
	~DeckCards(){
		delete[] cards;
	}
	void setDeskCards(); // создание колоды (видимо сразу рандомно)

private:
	Card* cards; // указатель на динамический массив с картами колоды
	const int size = 52; // размер колоды

};

// класс для игрока
class Player {
public:
	Player(){
		namePlayer = "New player";
		score = 0;
	}
	void setNamePlayer(std::string newName){
		this->namePlayer = newName;
	}
	std::string getNamePlayer(){
		return this->namePlayer;
	}
private:
	std::string namePlayer; //имя игрока
	int score; //счет игрока
};



int main() {



	return 0;
}
