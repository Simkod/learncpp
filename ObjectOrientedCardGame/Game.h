#pragma once
#include <vector>
#include "Card.h"
#include "Player.h"

#include <memory>

class Game
{
public:
    Game();
    ~Game();

    void AddCardToGame(Card CardName);
    void AddPlayerToGame(Player PlayerName);
    void ShuffleCards();
    bool takeBet(Player& player, const Card WinCard,const int playerguess, const int pbet);

private:
    std::vector<Card> CardsInGame;
    std::vector<Player> PlayersInGame;
};