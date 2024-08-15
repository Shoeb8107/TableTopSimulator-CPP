// Dealer.h

#pragma once

#include "Player.h"
#include "../../deck/deck.h"

class Dealer : public Player {
public:
	void play(Deck& deck);
};