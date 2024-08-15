// Deck.h

#pragma once

#include <iostream>
#include <vector>
#include <random>
#include "FrenchDeck.h"

class Deck {
public:
	void createFrenchDeck();

	void printDeck() const;

	void deckSize() const;

	void shuffleDeck();

	FrenchDeck dealCard();

private:
	std::vector<FrenchDeck> deck;

};