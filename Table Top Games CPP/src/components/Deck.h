// Deck.h

#pragma once

#include <iostream>
#include <vector>
#include <random>
#include <memory>
//#include "FrenchDeck.h"

template<typename CardType>
class Deck {
public:
	void createDeck();
	std::shared_ptr<CardType> dealCard();
	void printDeck() const;
	void deckSize() const;
	void shuffleDeck();

private:
	std::vector<std::shared_ptr<CardType>> deck;
};