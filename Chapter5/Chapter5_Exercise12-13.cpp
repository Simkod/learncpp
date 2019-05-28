//Bulls and Cows
//The program has a vector of four different integers in the range 0 to 9 (e.g., 1234 but not 1122) 
//It is the user’s task to discover those numbers by repeated guesses.
//Say the number to be guessed is 1234 and the user guesses 1359; the response should be “1 bull and 1
//cow” because the user got one digit(1) right and in the right position(a bull) and one digit(3) right but in the wrong
//position(a cow).
//The guessing continues until the user gets four bulls, that is, has the four digits correct and in the correct order.

#include <vector>
#include <time.h>
#include <iostream>
#include <algorithm>

using namespace std;

enum MatchCase
{
    NoMatch,
    Bull, //right number in right position
    Cow   //right number in wrong position
};

int main()
{
    int numberOfDigits(4);

    //Create 4 digit random vector. One digit only once
    vector<int> computerNumbers(numberOfDigits);
    srand((unsigned int)time(NULL));
    for (vector<int>::iterator vectIt = computerNumbers.begin(); vectIt != computerNumbers.end(); ++vectIt)
    {
        bool validNumber(false);

        while (!validNumber)
        {
            int randomDigit = rand() % 9 + 0;
            //check if randomDigit is already amongst numbers
            if (find(computerNumbers.begin(), computerNumbers.end(), randomDigit) == computerNumbers.end())
            {
                validNumber = true;
                *vectIt = randomDigit;
            }
        }
    }

    bool playerWon(false);
    vector<int> userDigits;
    vector<MatchCase> matchState(numberOfDigits);

    //Main loop
    while (!playerWon)
    {
        //ask user for its guess
        cout << "Give your number consisting of " << numberOfDigits << " digits: ";

        bool isDigit(false);
        char userInput(0);
        while (cin >> userInput)
        {
            if (!isdigit(userInput))
            {
                cout << endl;
                cout << "You entered a character instead of only integers. Please try again!";
                cout << endl;

                userDigits.clear();
                break;
            }
            else
            {
                int userDigit = userInput - '0';
                userDigits.push_back(userDigit);
            }
            if (userDigits.size() == numberOfDigits)
            {
                break;
            }

        }

        cout << "Your Numbers: ";
        for (vector<int>::iterator vectIt = userDigits.begin(); vectIt != userDigits.end(); ++vectIt)
        {
            cout << *vectIt;
        }
        cout << endl;

        //compare input with number, count bulls and cows
        for (vector<int>::iterator userDigitIt = userDigits.begin(); userDigitIt != userDigits.end(); ++userDigitIt)
        {
            for (vector<int>::iterator computerDigitIt = computerNumbers.begin(); computerDigitIt != computerNumbers.end(); ++computerDigitIt)
            {
                //check bull
                if (*computerDigitIt == *userDigitIt &&
                    distance(computerNumbers.begin(), computerDigitIt) == distance(userDigits.begin(), userDigitIt))
                {
                    matchState.at(distance(computerNumbers.begin(), computerDigitIt)) = Bull;
                    break;
                }
                //check cow
                else if (*computerDigitIt == *userDigitIt)
                {
                    matchState.at(distance(userDigits.begin(), userDigitIt)) = Cow;
                    break;
                }
            }
        }

        cout << "MatchState: ";
        for (vector<MatchCase>::iterator vectIt = matchState.begin(); vectIt != matchState.end(); ++vectIt)
        {
            cout << *vectIt;
        }
        cout << endl;

        //if all bulls-> playerwon;
        if (all_of(matchState.cbegin(), matchState.cend(), [](MatchCase currentCase) { return currentCase == Bull; }))
        {
            playerWon = true;
        }
        else
        {
            for (vector<MatchCase>::iterator vectIt = matchState.begin(); vectIt != matchState.end(); ++vectIt)
            {
                *vectIt = NoMatch;
            }
            userDigits.clear();
        }

    }

    //inform user
    cout << endl;
    cout << "YOU GOT IT RIGHT!" << endl;

    cout << "Computer: ";
    for (vector<int>::iterator vectIt = computerNumbers.begin(); vectIt != computerNumbers.end(); ++vectIt)
    {
        cout << *vectIt;
    }
    cout << endl;

    cout << "Your Numbers: ";
    for (vector<int>::iterator vectIt = userDigits.begin(); vectIt != userDigits.end(); ++vectIt)
    {
        cout << *vectIt;
    }
    cout << endl;

    system("Pause");

}