// Deck.cpp

#include "Deck.h"

template<typename CardType>
void Deck<CardType>::printDeck() const {
	for (auto& card : deck) {
		std::cout << card.getString() << '\n';
	}
	std::cout << "Total cards in deck: " << deck.size() << '\n';
}
template<typename CardType>
void Deck<CardType>::deckSize() const {
	std::cout << "SIZE OF DECK" << deck.size() << '\n';
}
template<typename CardType>
void Deck<CardType>::shuffleDeck() {
	std::random_device rd;
	std::mt19937 g(rd());
	std::shuffle(deck.begin(), deck.end(), g);
}
template<typename CardType>
std::shared_ptr<CardType> Deck<CardType>::dealCard() {
	if (deck.empty()) {
		throw std::out_of_range("No more cards in deck");
	}
	std::shared_ptr<CardType> dealtCard = deck.back();
	deck.pop_back();

	return dealtCard;
}
