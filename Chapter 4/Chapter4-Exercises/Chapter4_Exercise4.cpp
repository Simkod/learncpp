#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


bool askUserIfSmallerThan(int number)
{
    bool userIsTalented(false);
    bool smaller(true);

    cout << "Is your number smaller than " << number << " ?\n";

    char userAnswer('\0');

    while (!userIsTalented)
    {
        cin >> userAnswer;

        if (userAnswer == 'Y')
        {
            smaller = true;
            userIsTalented = true;
        }
        else if (userAnswer == 'N')
        {
            smaller = false;
            userIsTalented = true;
        }
        else
        {
            cout << "Please answer with 'Y' or 'N'!\n";
            userIsTalented = false;
        }
    }
    return smaller;
}

bool askUserIfDivideableBy(int divider)
{
    cout << "Is your number divideable by " << divider << " ?\n";

    bool divideable(true);
    char userAnswer('\0');
    bool userIsTalented(false);

    while (!userIsTalented)
    {
        cin >> userAnswer;

        if (userAnswer == 'Y')
        {
            divideable = true;
            userIsTalented = true;
        }
        else if (userAnswer == 'N')
        {
            divideable = false;
            userIsTalented = true;
        }
        else
        {
            cout << "Please answer with 'Y' or 'N'!\n";
            userIsTalented = false;
        }
    }
    return divideable;
}

void eraseElementsDividableBy(int divider, vector<int>* vectorPtr)
{
    bool divideableByTwo = askUserIfDivideableBy(divider);
    vector<int>::iterator vectIt = vectorPtr->begin();

    if (divideableByTwo)
    {
        //delete odd elements
        while (vectIt != vectorPtr->end())
        {
            if (*vectIt % divider != 0)
            {
                vectIt = vectorPtr->erase(vectIt);
            }
            else
            {
                ++vectIt;
            }
        }
    }
    else
    {
        while (vectIt != vectorPtr->end())
        {
            if (*vectIt % divider == 0)
            {
                vectIt = vectorPtr->erase(vectIt);
            }
            else
            {
                ++vectIt;
            }
        }
    }
}

int main()
{
    //Welcome user
    cout << "Hola User!\n";
    cout << "I will guess your number. Answer the questions with Yes or No (Y/N)\n\n";

    int minNumber(1);
    int maxNumber(100);
    int remainingQuestions(7);

    vector<int>* batchOfNumbers = new vector<int>;


    for (int i = 1; i <= maxNumber; ++i)
    {
        batchOfNumbers->push_back(i);
    }

    int divider = 2;
    eraseElementsDividableBy(divider, batchOfNumbers);
    --remainingQuestions;

    divider = 3;
    eraseElementsDividableBy(divider, batchOfNumbers);
    --remainingQuestions;

    while (remainingQuestions--)
    {
        vector<int>::iterator middleElementIt = batchOfNumbers->begin() + batchOfNumbers->size() / 2;

        bool isSmaller = askUserIfSmallerThan(*middleElementIt);

        if (isSmaller)
        {
            //delete every element above and the element itself
            batchOfNumbers->erase(middleElementIt, batchOfNumbers->end());
        }
        else
        {
            //delete every element under
            batchOfNumbers->erase(batchOfNumbers->begin(), middleElementIt);
        }
        if (batchOfNumbers->size() == 1)
        {
            break;
        }
    }

    int usersNumber = batchOfNumbers->at(0);

    //Tell the user what is his number
    cout << "Your number was " << usersNumber << "\n";
    system("Pause");

}