// Dealer.cpp

#include "Dealer.h"

void Dealer::play(Deck& deck) {
	while (calculateHandValue() < 17) {
		draw(deck.dealCard());
	}
}