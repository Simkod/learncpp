#include "Game.h"
#include <time.h>
#include <iostream>
#include "Card.h"

Game::Game() {
    Card J(Card::Figure::JACK);
    Card Q(Card::Figure::QUEEN);
    Card K(Card::Figure::KING);

    //Filling up Game with cards
    AddCardToGame(J);
    AddCardToGame(Q);
    AddCardToGame(K);
}

Game::~Game() {

}

void Game::AddCardToGame(Card CardName)
{
    CardsInGame.push_back(CardName);
}

void Game::AddPlayerToGame(Player PlayerName)
{
    PlayersInGame.push_back(PlayerName);
}

void Game::ShuffleCards()
{
    srand(time(NULL));
    for (int i = 0; i < 5; ++i) {
        int x = rand() % CardsInGame.size();
        int y = rand() % CardsInGame.size();
        Card temp = CardsInGame[x];
        CardsInGame[x] = CardsInGame[y];
        CardsInGame[y] = temp;
    }
}



bool Game::takeBet(
    Player& player,
    const Card WinCard, 
    const int playerguess,
    const int pbet)
{

    if (CardsInGame[playerguess].getsymbol() == WinCard.getsymbol()) {

        player.setmoney(3 * pbet);
        return true;
    }
    else {

        player.setmoney(-pbet);
        return false;
    }
}


