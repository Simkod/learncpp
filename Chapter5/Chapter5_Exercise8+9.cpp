//read and store N integers an sum them
//Handle all inputs, check them

#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <numeric>

using namespace std;

enum InputCases
{
    FirstInput,
    LoopInput
};

int getUserInput(InputCases currentCase)
{
    string userInput;

    if (currentCase == FirstInput)
    {
        cout << "Please enter the number of values you want to sum (press '|' to stop): ";
    }
    if (currentCase == LoopInput)
    {
        cout << "Please enter some integers (press '|' to stop): ";
    }

    cin >> userInput;
    cout << endl;

    //int checking
    while (true)
    {
        if (userInput == "|")
        {
            return INT_MIN;
        }

        bool charFound(false);
        for (char& ch : userInput)
        {           
            charFound = !isdigit(ch);
            if (charFound) break;
        }

        if (charFound)
        {
            cin.clear();
            cout << "You have entered wrong input." << endl << endl;
            cout << "Try again:" << endl;
            cin >> userInput;
        }
        else
        {
            break;
        }
    }

    int userNumber = stoi(userInput);

    return userNumber;
}

void printVectorElementsInBracket(vector<int>* input) 
{
    cout << "(";
    for (vector<int>::iterator vectIt = input->begin(); vectIt != input->end(); ++vectIt)
    {
        cout <<" " << *vectIt << " ";
    }
    cout << ")";
}

int main()
{
    InputCases ourCase(FirstInput);
    vector<int>* numbers = new vector<int>;

    //User Inputs + Handling + Store
        //Give N + check it
    int n = getUserInput(ourCase);
    if (n == INT_MIN) exit;
    ourCase = LoopInput;
        
        //Input integers until user want to terminate loop
    bool oneMoreInput(true);
    while (oneMoreInput)
    {
        //Input
        int userInput = getUserInput(LoopInput);
        if (userInput == INT_MIN)
        {
            oneMoreInput == false;
            if (numbers->size() < n)
            {
                cout << "You entered less integers than you want to sum." << endl;
                continue;
            }
            break;
        }
        else
        {
            numbers->push_back(userInput);
        }
        
            //Is N bigger than size of the vector?

    }
    //Logic
            //calculate sum
    int sum = accumulate(numbers->begin(), numbers->begin()+n, 0);
    //Output
    cout << "The sum of the first " << n << " of your numbers ";
    printVectorElementsInBracket(numbers);
    cout << " is: " << sum << endl;

    system("pause");
}