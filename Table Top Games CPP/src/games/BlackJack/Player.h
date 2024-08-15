// player.h

#pragma once

#include <iostream>
#include "../../deck/FrenchDeck.h"
#include <vector>

class Player {
public:
	void draw(FrenchDeck card);

	int calculateHandValue() const;

	void showHand() const;

protected:
	std::vector<FrenchDeck> hand;
};
