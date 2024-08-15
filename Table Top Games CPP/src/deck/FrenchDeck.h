// FrenchDeck.h

#pragma once

#include <string>

class FrenchDeck {
public:
	enum class Type {
		Number = -1,
		Jack = 11,
		Queen = 12,
		King = 13,
		Ace = 14
	};

	enum class Suite {
		Spades,
		Clubs,
		Diamonds,
		Hearts
	};

	FrenchDeck(Type type, Suite suite, int number = 0);

	std::string getString() const;

	Suite getSuite() const;
	Type getType() const;
	int getNumber() const;
private:
	Suite m_suite;
	Type m_type;
	int m_number;
	std::string m_name;

	std::string getCardTypeName(Type type);
	std::string getSuiteName(Suite suite) const;
	std::string getCardTypeName() const;
};