//Rock, Paper, Scissors

#define stringify( name ) # name

#include <vector>
#include <iostream>
#include <string>
#include <time.h>

using namespace std;

int main()
{
    enum Figure
    {
        Rock,
        Paper,
        Scissors 
    };

    enum GameResult
    {
        UserWon,
        ComputerWon,
        Tie
    };
    //vector container
    vector<Figure> figuresToSelectfrom;
    figuresToSelectfrom.push_back(Rock);
    figuresToSelectfrom.push_back(Paper);
    figuresToSelectfrom.push_back(Scissors);

    //Standing
    int userWins(0);
    int computerWins(0);
    int ties(0);

    //while(player wants to play)
    bool newGame(true);
    while (newGame)
    {
        //user input (R P S)
        cout << "Choose 'Rock', 'Paper' or 'Scissors' and type it:";
        string userInput("");
        cin >> userInput;
        cout << endl;
        //Translate input to user selection
        Figure userSelection;
        if (userInput == "Rock" || userInput == "rock")
        {
            userSelection = Rock;
        }
        else if (userInput == "Paper" || userInput == "paper")
        {
            userSelection = Paper;
        }
        else if (userInput == "Scissors" || userInput == "scissors")
        {
            userSelection = Scissors;
        }
        else
        {
            cout << "Input Error!";
        }

        //logic
            //computer selection
        Figure computerSelection;

        srand((unsigned int)time(NULL));
        computerSelection = figuresToSelectfrom.at(rand() % figuresToSelectfrom.size());
        cout << "Computer selected: ";
        if (computerSelection == Rock) { cout << "Rock" << endl; }
        else if (computerSelection == Paper) { cout << "Paper" << endl; }
        else if (computerSelection == Scissors) { cout << "Scissors" << endl; };

        //comparison (switch)
        GameResult result;
        if (userSelection == computerSelection)
        {
            result = Tie;
            ++ties;
        }
        else if (userSelection == Rock && computerSelection == Paper)
        {
            result = ComputerWon;
            ++computerWins;
        }
        else if (userSelection == Rock && computerSelection == Scissors)
        {
            result = UserWon;
            ++userWins;
        }
        else if (userSelection == Paper && computerSelection == Rock)
        {
            result = UserWon;
            ++userWins;
        }
        else if (userSelection == Paper && computerSelection == Scissors)
        {
            result = ComputerWon;
            ++computerWins;
        }
        else if (userSelection == Scissors && computerSelection == Rock)
        {
            result = ComputerWon;
            ++computerWins;
        }
        else if (userSelection == Scissors && computerSelection == Paper)
        {
            result = UserWon;
            ++userWins;
        }

        //output
            //who won
        if (result == UserWon) { cout << "YOU WON!" << endl; }
        else if (result == ComputerWon) { cout << "COMPUTER WON!" << endl; }
        else if (result == ComputerWon) { cout << "TIED!" << endl; };
        //standing
        cout << "Wins:" << endl;
        cout << "User: " << userWins << "\t";
        cout << "Ties: " << ties << "\t";
        cout << "Computer: " << computerWins << endl << endl;
        //newgame?
        cout << "New Game? (Y/N)";
        char userNewGameInput('\0');
        cin >> userNewGameInput;
        if (userNewGameInput == 'Y')
        {
            newGame = true;
        }
        else if (userNewGameInput == 'N')
        {
            newGame = false;
        }
        else
        {
            cout << "Input Fail";
        }
    }


}




