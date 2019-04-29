#include "Player.h"
#include <process.h>
#include "Card.h"
#include "Game.h"

#include <iostream>
//Card game again

int main() {

    
    Player Danielo(100);    //Create Player with 100 money   

    Card WinningCard(Card::Figure::QUEEN);   //Defining the winning Card
    
    Game OurGame;       //Create Game
    
    OurGame.AddPlayerToGame(Danielo);       //Adding a Player

    //Play
    while (Danielo.getmoney() > 0) {

        //Player Guesses
        int PlayerGuess;
        std::cout << "Guess the position of the Queen(1 2 or 3): ";
        std::cin >> PlayerGuess;
        PlayerGuess = PlayerGuess - 1;

        //Player bets
        int PlayerBet;
        std::cout << "Place your bet: ";
        std::cin >> PlayerBet;

        OurGame.ShuffleCards();

        if (OurGame.takeBet(Danielo, WinningCard, PlayerGuess, PlayerBet))
        {
            std::cout << "You won!\n";
            std::cout << "You have now:" << Danielo.getmoney()<<"\n";
        }
        else {
            std::cout << "You loose!\n";
            std::cout << "You have now:" << Danielo.getmoney() << "\n";
        }
    }
    
}