#include <iostream>


class Card {
public:
	Card() {
		this->suit = static_cast<Suit>(0);
		this->value = static_cast<valueCard>(1);
		status = 0;
	}
	enum class Suit { CLUBS, DIAMONDS, HEARTS, SPADES };
	enum class valueCard {
		  TWO = 2,
		  THREE = 3,
		  FOUR = 4,
		  FIVE = 5,
		  SIX = 6,
		  SEVEN = 7,
		  EIGHT = 8,
		  NINE = 9,
		  TEN = 10,
		  JACK = 10,
		  KING = 10,
		  QUEEN = 10,
		  ACE = 1
	};
	void Flip() {
		if (this->status)
			this->status = true;
		else
			this->status = false;
	}
	valueCard getValue() {
		return value;
	}
private:
	Suit suit;
	valueCard value;
	bool status;
};


int main() {
	Card card;
	std::cout << static_cast<int>(card.getValue());

return 0;
}
