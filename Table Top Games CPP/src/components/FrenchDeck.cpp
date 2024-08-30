#include "FrenchDeck.h"

FrenchDeck::FrenchDeck(Type type, Suite suite, int number) : m_type(type), m_suite(suite), m_number(number) {
	if (type != Type::Number) {
		this->m_number = static_cast<int>(type);
	}
	m_name = getCardTypeName();
}

std::string FrenchDeck::getString() const {
	return m_name + " of " + getSuiteName(m_suite);
}

FrenchDeck::Suite FrenchDeck::getSuite() const { return m_suite; }
FrenchDeck::Type FrenchDeck::getType() const { return m_type; }
int FrenchDeck::getNumber() const { return m_number; }

std::string FrenchDeck::getSuiteName(Suite suite) const {
	switch (suite) {
	case Suite::Spades:
		return "Spades";
	case Suite::Clubs:
		return "Clubs";
	case Suite::Diamonds:
		return "Diamonds";
	case Suite::Hearts:
		return "Hearts";
	default:
		return "Unknown";
	}
}

std::string FrenchDeck::getCardTypeName() const {
	switch (m_type) {
	case Type::Jack:
		return "Jack";
	case Type::Queen:
		return "Queen";
	case Type::King:
		return "King";
	case Type::Ace:
		return "Ace";
	case Type::Number:
		return std::to_string(m_number);
	default:
		return "Unknown";
	}
}

template<>
void Deck<FrenchDeck>::createDeck() {
	static const int numbers[] = { 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	for (int suite = 0; suite < 4; ++suite) {
		auto currentSuite = static_cast<FrenchDeck::Suite>(suite);
		for (int number : numbers){
			deck.emplace_back(std::make_shared<FrenchDeck>(FrenchDeck::Type::Number, currentSuite, number));
		}

	deck.emplace_back(std::make_shared<FrenchDeck>(FrenchDeck::Type::Jack, currentSuite));
	deck.emplace_back(std::make_shared<FrenchDeck>(FrenchDeck::Type::Queen, currentSuite));
	deck.emplace_back(std::make_shared<FrenchDeck>(FrenchDeck::Type::King, currentSuite));
	deck.emplace_back(std::make_shared<FrenchDeck>(FrenchDeck::Type::Ace, currentSuite));
	}
}