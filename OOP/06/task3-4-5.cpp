#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Card {
public:
	enum class Suit { CLUBS, DIAMONDS, HEARTS, SPADES };
	enum class valueCard {
		ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN,
		JACK = 10, KING = 10, QUEEN = 10 };

	Card(valueCard vc = valueCard::KING, Suit s = Suit::DIAMONDS, bool ifu = false) : value(vc), suit(s), status(ifu) {}

	void Flip() {
		status = !(status);
	}

	int getValue() const {
		if (status) {
			return static_cast<int>(value);
		}
		return 0;
	}

	string getSuitName() const {
		switch (suit) {
		case Suit::CLUBS:
			return "CLUBS";
		case Suit::DIAMONDS:
			return "DIAMONDS";
		case Suit::HEARTS:
			return "HEARTS";
		case Suit::SPADES:
			return "SPADES";
		}
	}

	string getValueCard() const {
		if (value == valueCard::ACE)
			return "ACE";
		if (value == valueCard::TWO)
			return "TWO";
		if (value == valueCard::THREE)
			return "THREE";
		if (value == valueCard::FOUR)
			return "FOUR";
		if (value == valueCard::FIVE)
			return "FIVE";
		if (value == valueCard::SIX)
			return "SIX";
		if (value == valueCard::SEVEN)
			return "SEVEN";
		if (value == valueCard::EIGHT)
			return "EIGHT";
		if (value == valueCard::NINE)
			return "NINE";
		if (value == valueCard::TEN)
			return "TEN";
		if (value == valueCard::JACK)
			return "JACK";
		if (value == valueCard::KING)
			return "KING";
		if (value == valueCard::QUEEN)
			return "QUEEN";
	}

	friend ostream& operator<<(ostream &out, const Card &card) {
		if (card.status) {
		out << card.getSuitName() << " " << card.getValueCard() << "\n";
		}
		else
			out << "XX \n";
		return out;
	}

private:
	Suit suit;
	valueCard value;
	bool status;
};

class Hand {
public:
	Hand() {
		m_cards.reserve(7);
	}
	virtual ~Hand() {
		Clear();
	}

	void Add(Card* pCard) {
		m_cards.push_back(pCard);
	}
	void Clear() {
		for (vector<Card*>::iterator it = m_cards.begin(); it != m_cards.end(); ++it) {
			delete* it;
			*it = 0;
		}
		m_cards.clear();
	}
	int GetTotal() const {
		if (m_cards.empty())
			return 0;
		if (Hand::m_cards[0]->getValue() == 0)
			return 0;
		int sum = 0;
		bool Ace_of_Base = true;
		for (vector<Card*>::const_iterator it = m_cards.begin(); it != m_cards.end(); ++it) {
			if ((*it)->getValue() == 1 && Ace_of_Base && sum < 11) {
				Ace_of_Base = false;
				sum += 11;
			}
			else {
				sum += (*it)->getValue();
			}
		}
		return sum;
	}

protected:
	vector<Card*> m_cards;
};

class GenericPlayer : public Hand {
public:
	virtual bool IsHitting() = 0;

	bool IsBoosted() const {
		if (Hand::GetTotal() > 21)
			return false;
		else
			return true;
	}
	void Bust() const {
		cout << "Player " << name << " have is a bust!" << endl;
	}
protected:
	string name;
};

// task 3
class Player : public GenericPlayer {
public:
	bool IsHitting() override {
		char c = '\0';
		while ((c != 'Y' || c != 'y') || (c != 'N' || c != 'n')) {
			cout << "Need more card? (Y/N)\n";
			cin >> c;
			if (c == 'Y' || c == 'y')
				return true;
			if (c == 'N' || c == 'n')
				return false;
			cout << "invalid character!\n";
		}
	}

	void Win() const {
		cout << "The player " << name << " is win!\n";
	}

	void Lose() const {
		cout << "The player " << name << " is lose!\n";
	}

	void Push() const {
		cout << "The player " << name << " played in a draw!\n";
	}
};

// task 4
class House : public GenericPlayer {
public:
	bool IsHitting() override {
		if (GetTotal() <= 16) {
			return true;
		}
		return false;
	}

	void FlipFirstCard() {
		if (!m_cards.empty()) {
			m_cards[0]->Flip();
		}
	}
};

int main() {

	Card card;
	card.Flip();
	cout << card;

	return 0;
}