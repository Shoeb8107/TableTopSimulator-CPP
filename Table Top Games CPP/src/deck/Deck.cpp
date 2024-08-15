// Deck.cpp

#include "Deck.h"

void Deck::createFrenchDeck() {
	static const int numbers[] = { 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	for (int suite = 0; suite < 4; ++suite) {
		auto currentSuite = static_cast<FrenchDeck::Suite>(suite);
		for (int number : numbers) {
			deck.emplace_back(FrenchDeck::Type::Number, currentSuite, number);
		}
		deck.emplace_back(FrenchDeck::Type::Jack, currentSuite);
		deck.emplace_back(FrenchDeck::Type::Queen, currentSuite);
		deck.emplace_back(FrenchDeck::Type::King, currentSuite);
		deck.emplace_back(FrenchDeck::Type::Ace, currentSuite);
	}
}

void Deck::printDeck() const {
	for (auto& card : deck) {
		std::cout << card.getString() << '\n';
	}
	std::cout << "Total cards in deck: " << deck.size() << '\n';
}

void Deck::deckSize() const {
	std::cout << "SIZE OF DECK" << deck.size() << '\n';
}

void Deck::shuffleDeck() {
	std::random_device rd;
	std::mt19937 g(rd());
	std::shuffle(deck.begin(), deck.end(), g);
}

FrenchDeck Deck::dealCard() {
	if (deck.empty()) {
		throw std::out_of_range("No more cards in deck");
	}
	FrenchDeck dealtCard = deck.back();
	deck.pop_back();
	return dealtCard;
}
