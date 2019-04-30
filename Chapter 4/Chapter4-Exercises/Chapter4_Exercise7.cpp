//Basic Calculator
//4 basic math operations (* , / , + , -)
//Two input values
//Input: int int (digit or spelled out) operator e.g.(4 9 +) or (four nine +)
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int translateUserInput(string userInput)
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

    int numberTranslated(0);

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
        return stoi(userInput);
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
        return distance(numbersSpelledOut.begin(), vectIt);
    }
    else
    {
        cout << "Inputerror";
    }
}

int main()
{
    //ask input
    cout << "One digit basic calculator" << endl;
    cout << "Please give your input as: onedigitnumber onedigitnumber operator, with digits (e.g. '4 7 +') or (four seven +)" << endl << endl;

    string firstNumberString;
    string secondNumberString("");
    char mathOperator('\0');

    cout << "Please give your numbers and the operation: " << endl;
    cin >> firstNumberString >> secondNumberString >> mathOperator;
    

    //Input handling 
        //Input checking missing

    int firstNumber = translateUserInput(firstNumberString);
    int secondNumber = translateUserInput(secondNumberString);

    //Logic

    int result(0);
    switch (mathOperator)
    {
    case '+':
        result = firstNumber + secondNumber;
        break;
    case '-':
        result = firstNumber - secondNumber;
        break;
    case '*':
        result = firstNumber * secondNumber;
        break;
    case '/':
        result = firstNumber / secondNumber;
        break;
    default:
        break;
    }

    //Output
    cout << result << endl;
    system("pause");
}




