// BlackjackGame.cpp

#include "BlackjackGame.h"

BlackjackGame::BlackjackGame() {
    deck.createFrenchDeck();
    deck.shuffleDeck();
    deck.deckSize();
}

void BlackjackGame::start() {
    dealInitialCards();
    playerTurn();
    dealerTurn();
    determineWinner();
}

void BlackjackGame::dealInitialCards() {
    player.draw(deck.dealCard());
    player.draw(deck.dealCard());
	dealer.draw(deck.dealCard());
	dealer.draw(deck.dealCard());

	std::cout << "Player's hand: " << player.calculateHandValue() << '\n';
	std::cout << "Dealer's hand:" << dealer.calculateHandValue() << '\n';

}

void BlackjackGame::playerTurn() {
	while (true) {
		std::cout << "Hit or Stand? (h/s): ";
		char action;
		std::cin >> action;
		if (action == 'h') {
			player.draw(deck.dealCard());
			std::cout << "Player's hand: ";
			player.showHand();
			if (player.calculateHandValue() > 21) {
				std::cout << "Bust!" << '\n';
				return;
			}

		}
		else {
			break;
		}
	}
}

void BlackjackGame::dealerTurn() {
	dealer.play(deck);
	std::cout << "dealer's hand: ";
	dealer.showHand();
}

void BlackjackGame::determineWinner() {
	int playerTotal = player.calculateHandValue();
	int dealerTotal = dealer.calculateHandValue();

	if (playerTotal > 21) {
		std::cout << "dealer wins!" << '\n';
	}
	else if (dealerTotal > 21 || playerTotal > dealerTotal) {
		std::cout << "player wins!" << '\n';
	}
	else if (dealerTotal == playerTotal) {
		std::cout << "push!" << '\n';
	}
	else {
		std::cout << "dealer wins!" << '\n';
	}
}
