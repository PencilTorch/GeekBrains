#include <iostream>
#include <vector>

class Card {
public:
	Card() {
		suit = static_cast<Suit>(0);
		value = static_cast<valueCard>(1);
		status = 0;
	}
	Card(int suit, int value) {
		this->suit = static_cast<Suit>(suit);
		this->value = static_cast<valueCard>(value);
		status = 0;
	}
	enum class Suit { CLUBS, DIAMONDS, HEARTS, SPADES };
	enum class valueCard {
		ONE = 1,
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
		ACE = 11
	};
	void Flip() {
		if (status)
			status = true;
		else
			status = false;
	}
	int getValue() {
		return static_cast<int>(value);
	}
private:
	Suit suit;
	valueCard value;
	bool status;
};

class Hand {
public:
	void Add(Card* card) {
		hand.push_back(card);
	}
	void Clear() {
		hand.clear();
	}
	int GetValue() {
		int sum = 0;
		if (hand.size() != 0) {
			for (int i = 0; i < hand.size(); ++i) {
				sum += hand[i]->getValue();
			}
		}
		return sum;
	}
private:
	std::vector<Card*> hand;
};


int main() {
	Card card(1, 6);
	Card* card2 = &card;
	Hand hand;
	hand.Add(card2);
	std::cout << hand.GetValue();
	hand.Clear();
	std::cout << hand.GetValue();

	return 0;
}