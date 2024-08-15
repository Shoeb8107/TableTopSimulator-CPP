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