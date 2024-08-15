// Player.cpp

#include "Player.h"

void Player::draw(FrenchDeck card) {
	hand.push_back(card);
}

int Player::calculateHandValue() const {
	int total = 0;
	int aces = 0;
	for (const auto& currentCard : hand) {
		if (currentCard.getNumber() > 10) {
			total += 10;
		}
		else if (currentCard.getType() == FrenchDeck::Type::Ace) {
			++aces;
			total += 11;
		}
		else {
			total += currentCard.getNumber();
		}
	}
	while (total > 21 && aces) {
		--aces;
		total -= 10;
	}
	return total;
}

void Player::showHand() const {
	for (const auto& card : hand) {
		std::cout << card.getString() << ", ";
	}
	std::cout << "Total Value: " << calculateHandValue() << '\n';
}