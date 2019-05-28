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
#include <string>

using namespace std;

enum MatchCase
{
    NoMatch,
    Bull, //right number in right position
    Cow   //right number in wrong position
};

vector<int>* createRandomNumberVector(int digitNumber)
{
    vector<int>* outputNumbers = new vector<int>(digitNumber);
    srand((unsigned int)time(NULL));
    for (vector<int>::iterator vectIt = outputNumbers->begin(); vectIt != outputNumbers->end(); ++vectIt)
    {
        bool validNumber(false);

        while (!validNumber)
        {
            int randomDigit = rand() % 9 + 0;
            //check if randomDigit is already amongst numbers
            if (find(outputNumbers->begin(), outputNumbers->end(), randomDigit) == outputNumbers->end())
            {
                validNumber = true;
                *vectIt = randomDigit;
            }
        }
    }
    return outputNumbers;
}

vector<int>* getUserDigits(int digitNumber)
{
    vector<int>* outputDigits = new vector<int>;
    while (true)
    {
        if (outputDigits->size() == digitNumber)
        {
            break;
        }

        cout << "Give your number consisting of " << digitNumber << " digits: ";

        string input;
        getline(cin, input);
        for (char& c : input)
        {
            if (outputDigits->size() == digitNumber)
            {
                break;
            }

            if (!isdigit(c))
            {
                cout << endl;
                cout << "You entered a character instead of only integers. Please try again!";
                cout << endl;

                outputDigits->clear();
                break;
            }
            else
            {
                int userDigit = c - '0';
                outputDigits->push_back(userDigit);
            }
        }
    }
    return outputDigits;
}

template <typename myType>
void printVector(vector<myType>* myVector)
{
    for (typename vector<myType>::iterator vectIt = myVector->begin(); vectIt != myVector->end(); ++vectIt)
    {
        cout << *vectIt;
    }
    cout << endl;
}

vector<MatchCase>* getMatches(vector<int>* compareThis, vector<int>* compareToThat)
{
    vector<MatchCase>* outputVector = new vector<MatchCase>(compareToThat->size());

    //compare input with number, count bulls and cows
    for (vector<int>::iterator userDigitIt = compareThis->begin(); userDigitIt != compareThis->end(); ++userDigitIt)
    {
        for (vector<int>::iterator computerDigitIt = compareToThat->begin(); computerDigitIt != compareToThat->end(); ++computerDigitIt)
        {
            //check bull
            if (*computerDigitIt == *userDigitIt &&
                distance(compareToThat->begin(), computerDigitIt) == distance(compareThis->begin(), userDigitIt))
            {
                outputVector->at(distance(compareToThat->begin(), computerDigitIt)) = Bull;
                break;
            }
            //check cow
            else if (*computerDigitIt == *userDigitIt)
            {
                outputVector->at(distance(compareThis->begin(), userDigitIt)) = Cow;
                break;
            }
        }
    }
    return outputVector;
}

void resetMatchState(vector<MatchCase>* vectorToReset)
{
    for (vector<MatchCase>::iterator vectIt = vectorToReset->begin(); vectIt != vectorToReset->end(); ++vectIt)
    {
        *vectIt = NoMatch;
    }
}

bool onlyBullsIn(vector<MatchCase>* vectorToCheck)
{
    return all_of(vectorToCheck->cbegin(), vectorToCheck->cend(), [](MatchCase currentCase) { return currentCase == Bull; });
}

void playerWonOutput(vector<int>* computerNumbers, vector<int>* userNumbers)
{
    cout << endl;
    cout << "YOU GOT IT RIGHT!" << endl;
    cout << "Computer: ";
    printVector(computerNumbers);
    cout << "Your Numbers: ";
    printVector(userNumbers);
    cout << endl;
}

int main()
{
    int numberOfDigits(4);

    vector<int>* computerDigits = createRandomNumberVector(numberOfDigits);
    vector<int>* userDigits = new vector<int>;

    //Main loop
    bool playerWon(false);
    while (!playerWon)
    {
        vector<MatchCase>* matchState = new vector<MatchCase>(numberOfDigits);

        userDigits = getUserDigits(numberOfDigits);
        matchState = getMatches(userDigits, computerDigits);

        cout << "Your Numbers: ";
        printVector(userDigits);
        cout << "MatchState: ";
        printVector(matchState);

        if (onlyBullsIn(matchState))
        {
            playerWon = true;
        }
        else
        {
            resetMatchState(matchState);
            userDigits->clear();
        }
    }

    playerWonOutput(computerDigits, userDigits);

    system("Pause");

}