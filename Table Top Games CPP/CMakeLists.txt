# CMakeList.txt : CMake project for Table Top Games CPP, include source and define
# project specific logic here.
#

# Add source to this project's executable.
cmake_minimum_required(VERSION 3.12)
project(BlackJack)

set(CMAKE_CXX_STANDARD 20)

include_directories("F:/Repos/Table Top Games CPP/src")

add_executable(BlackJackProject
	src/main.cpp
    src/games/blackjack/BlackjackGame.cpp
    src/games/blackjack/Player.cpp
    src/games/blackjack/Dealer.cpp
    src/deck/Deck.cpp
    src/deck/FrenchDeck.cpp
    src/games/Game.cpp)

# TODO: Add tests and install targets if needed.


