// BlackjackGame.h
#pragma once

#include <iostream>
#include "Player.h"
#include "Dealer.h"
#include "../../deck/Deck.h"
#include "../../deck/FrenchDeck.h"

class BlackjackGame {
public:
    BlackjackGame();
    void start();
private:
    Player player;
    Dealer dealer;
    Deck deck;

    void dealInitialCards();
    void playerTurn();
    void dealerTurn();
    void determineWinner();
};