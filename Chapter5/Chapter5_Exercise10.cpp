//read and store N integers an sum them
//Handle all inputs, check them

#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <numeric>
#include <iomanip>

using namespace std;

enum InputCases
{
    FirstInput,
    LoopInput
};

double getUserInput(InputCases currentCase)
{
    string userInput;

    if (currentCase == FirstInput)
    {
        cout << "Please enter the number of values you want to sum (press '|' to stop): ";
    }
    if (currentCase == LoopInput)
    {
        cout << "Please enter some doubles and press '|' to stop (double format: #.#): ";
    }

    cin >> userInput;
    cout << endl;

    //double checking
    while (true)
    {
        if (userInput == "|")
        {
            return INT_MIN;
        }

        bool charFound(false);
        for (char& ch : userInput)
        {
            if (ch == '.') continue;

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

    double userNumber = stod(userInput);

    return userNumber;
}

void printVectorElementsInBracket(vector<double>* input)
{
    cout << "(";
    for (vector<double>::iterator vectIt = input->begin(); vectIt != input->end(); ++vectIt)
    {
        cout << fixed << setprecision(2) << " " << *vectIt << " ";
    }
    cout << ")";
}

int main()
{
    InputCases ourCase(FirstInput);
    vector<double>* numbers = new vector<double>;

    //User Inputs + Handling + Store
        //Give N + check it
    double n = getUserInput(ourCase);
    if (n == INT_MIN) exit;
    ourCase = LoopInput;

    //Input integers until user want to terminate loop
    bool oneMoreInput(true);
    while (oneMoreInput)
    {
        //Input
        double userInput = getUserInput(LoopInput);
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
    double sum = accumulate(numbers->begin(), numbers->begin() + n, 0);

        //calculate adjacent differences
    vector<double>* differences = new vector<double>;
    
    differences->push_back(0); //first element is 0

    for (vector<double>::iterator vectIt = numbers->begin() + 1; vectIt != numbers->end(); ++vectIt)
    {
        differences->push_back(*vectIt - *(vectIt - 1));
    }

    //Output
        //sum
    cout << "The sum of the first " << n << " of your numbers ";
    printVectorElementsInBracket(numbers);
    cout << " is: " << sum << endl;

        //differences
    cout << "The adjacent differences are of your numbers are: ";
    printVectorElementsInBracket(differences);
    cout << endl;


    system("pause");
}