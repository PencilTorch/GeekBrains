#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <time.h>
using namespace std;

class Card {
public:
	enum class Suit { CLUBS, DIAMONDS, HEARTS, SPADES };
	enum class valueCard {
		ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN,
		JACK, KING, QUEEN
	};

	Card(valueCard vc = valueCard::KING, Suit s = Suit::DIAMONDS, bool ifu = true) : value(vc), suit(s), status(ifu) {}

	void Flip() {
		status = !(status);
	}

	int getValue() const {
		int val = 0;
		if (status) {
			val =  static_cast<int>(value);
			if (val > 10) {
				val = 10;
			}
		}
		return val;
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
		default:
			return "";
		}
	}

	string getValueCard() const {
		switch (value) {
		case Card::valueCard::ACE:
			return "ACE";
		case Card::valueCard::TWO:
			return "TWO";
		case Card::valueCard::THREE:
			return "THREE";
		case Card::valueCard::FOUR:
			return "FOUR";
		case Card::valueCard::FIVE:
			return "FIVE";
		case Card::valueCard::SIX:
			return "SIX";
		case Card::valueCard::SEVEN:
			return "SEVEN";
		case Card::valueCard::EIGHT:
			return "EIGHT";
		case Card::valueCard::NINE:
			return "NINE";
		case Card::valueCard::TEN:
			return "TEN";
		case Card::valueCard::JACK:
			return "JACK";
		case Card::valueCard::KING:
			return "KING";
		case Card::valueCard::QUEEN:
			return "QUEEN";
		default:
			return "";
		}
	}

	bool getStatusCard() const {
		return status;
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
	GenericPlayer(const string& namePlayer = "") : name(namePlayer) {}
	virtual ~GenericPlayer() {}

	virtual bool IsHitting() = 0;
	bool IsBoosted() const {
		return (Hand::GetTotal() > 21);
	}
	void Bust() const {
		cout << "Player " << name << " have is a bust!" << endl;
	}
	friend ostream& operator<<(ostream& out, const GenericPlayer& gp) {
		out << "Name player: " << gp.name << ". Cards in hand:\n";
		if (!gp.m_cards.empty()) {
			for (vector<Card*>::const_iterator it = gp.m_cards.begin(); it != gp.m_cards.end(); ++it) {
				if ((*it)->getStatusCard()) {
					out << (*it)->getSuitName() << " " << (*it)->getValueCard() << "\n";
				}
				else
					out << "XX \n";
			}
			out << "Total points: " << gp.GetTotal() << "\n";
			return out;
		}
		else
			out << "<empty>\n";
	}

protected:
	string name;
};


class Player : public GenericPlayer {
public:
	Player(const string& namePlayer = "") {
		name = namePlayer;
	}
	virtual ~Player() {}

	bool IsHitting() override {
		cout << name << ", do you want a hit? (Y/N): ";
		char c = '\0';
		cin >> c;
		return (c == 'y' || c == 'Y');
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

class House : public GenericPlayer {
public:
	House(const string& namePlayer = "House") {
		name = namePlayer;
	}
	virtual ~House() {}

	bool IsHitting() override {
		return (GetTotal() <= 16);
	}

	void FlipFirstCard() {
		if (!m_cards.empty()) {
			m_cards[0]->Flip();
		}
		else
			cout << "No card to flip!\n";
	}
};

// task 3
class Deck : public Hand {
public:
	Deck() {
		m_cards.reserve(52);
		Populate();
	}
	virtual ~Deck() {}

	void Populate() {
		Clear();
		for (int s = 0; s < 4; ++s) {
			for (int r = 1; r < 14; ++r) {
				Add(new Card(static_cast<Card::valueCard>(r), static_cast<Card::Suit>(s)));
			}
		}
	}
	void Shuffle() {
		random_shuffle(m_cards.begin(), m_cards.end());
	}
	void Deal(Hand& aHand) {
		if (!m_cards.empty()) {
			aHand.Add(m_cards.back());
			m_cards.pop_back();
		}
		else
			cout << "Out of cards. Unable to deal.\n";
	}
	void AddItionalCards(GenericPlayer& aGenericPlayer) {
		cout << endl;
		while (!(aGenericPlayer.IsBoosted()) && aGenericPlayer.IsHitting()) {
			Deal(aGenericPlayer);
			cout << aGenericPlayer << endl;
			if (aGenericPlayer.IsBoosted())
				aGenericPlayer.Bust();
		}
	}
private:

};

// task 4
class Game {
public:
	Game(const vector<string>& names) {
		for (vector<string>::const_iterator it = names.begin(); it != names.end(); ++it) {
			m_players.push_back(Player(*it));
		}
		srand(static_cast<unsigned int>(time(0)));
		m_deck.Populate();
		m_deck.Shuffle();
	}
	
	void Play() {
		for (int i = 0; i < 2; ++i) {
			for (vector<Player>::iterator it = m_players.begin(); it != m_players.end(); ++it) {
				m_deck.Deal(*it);
			}
			m_deck.Deal(m_house);
		}
		m_house.FlipFirstCard();
		for (vector<Player>::iterator it = m_players.begin(); it != m_players.end(); ++it) {
			cout << *it << endl;
		}
		cout << m_house << endl;
		for (vector<Player>::iterator it = m_players.begin(); it != m_players.end(); ++it) {
			m_deck.AddItionalCards(*it);
		}
		m_house.FlipFirstCard();
		cout << endl << m_house;
		m_deck.AddItionalCards(m_house);
		if (m_house.IsBoosted()) {
			for (vector<Player>::iterator it = m_players.begin(); it != m_players.end(); ++it) {
				if (!(it->IsBoosted()))
					it->Win();
			}
		}
		else {
			for (vector<Player>::iterator it = m_players.begin(); it != m_players.end(); ++it) {
				if (!(it->IsBoosted())) {
					if (it->GetTotal() > m_house.GetTotal())
						it->Win();
					else if (it->GetTotal() < m_house.GetTotal())
						it->Lose();
					else
						it->Push();
				}
			}
		}
		for (vector<Player>::iterator it = m_players.begin(); it != m_players.end(); ++it) {
			it->Clear();
		}
		m_house.Clear();
	}

private:
	Deck m_deck;
	House m_house;
	vector<Player> m_players;
};

// task 5
int main() {
	cout << "\t\tWelcome to Blackjack!\n\n";

	int numPlayers = 0;
	while (numPlayers < 1 || numPlayers > 7)
	{
		cout << "How many players? (1 - 7): ";
		cin >> numPlayers;
	}

	vector<string> names;
	string name;
	for (int i = 0; i < numPlayers; ++i)
	{
		cout << "Enter player name: ";
		cin >> name;
		names.push_back(name);
	}
	cout << endl;

	// игровой цикл
	Game aGame(names);
	char again = 'y';
	while (again != 'n' && again != 'N')
	{
		aGame.Play();
		cout << "\nDo you want to play again? (Y/N): ";
		cin >> again;
	}

	

	return 0;
}
