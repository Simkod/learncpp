//Number Translator

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<string> numbersSpelledOut = { "zero"
                                       ,"one"
                                       ,"two"
                                       ,"three"
                                       ,"four"
                                       ,"five"
                                       ,"six"
                                       ,"seven"
                                       ,"eight"
                                       ,"nine"
    };


    //ask input
    cout << "Number Translator" << endl << endl;
       
    string numberTranslated("");
    bool isUserTalented(false);
    
    while (!isUserTalented)
    {
        cout << "Please give your input as a number spelled out or as a digit between 0-9: ";

        int userNumber(0);
        string userInput("");
        cin >> userInput;

        if (userInput == "0"
            || userInput == "1"
            || userInput == "2"
            || userInput == "3"
            || userInput == "4"
            || userInput == "5"
            || userInput == "6"
            || userInput == "7"
            || userInput == "8"
            || userInput == "9"
            )
        {
            userNumber = stoi(userInput);
            numberTranslated = numbersSpelledOut.at(userNumber);
            isUserTalented = true;
        }
        else if (userInput == "zero"
            || userInput == "one"
            || userInput == "two"
            || userInput == "three"
            || userInput == "four"
            || userInput == "five"
            || userInput == "six"
            || userInput == "seven"
            || userInput == "eight"
            || userInput == "nine"
            )
        {
            vector<string>::iterator vectIt = find(numbersSpelledOut.begin(), numbersSpelledOut.end(), userInput);
            int index = distance(numbersSpelledOut.begin(), vectIt);
            numberTranslated = to_string(index);
            isUserTalented = true;
        }
        else
        {
            cout << endl << "You have to give a number as a digit (e.g. 7) or spelled out (seven)" << endl;
            isUserTalented = false;
        }
 
    }

    //Output
    cout << numberTranslated << endl;
    system("pause");
}