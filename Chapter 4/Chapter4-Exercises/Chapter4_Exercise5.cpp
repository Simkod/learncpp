//Basic Calculator
//4 basic math operations (* , / , + , -)
//Two input values
//Input: double double operator e.g.(24.5 33.2 +)
#include <iostream>

using namespace std;

int main()
{
    //ask input
    cout << "Basic calculator" << endl;
    cout << "Please give your input as: firstnumber secondnumber operator, e.g. '24.5 33.2 +'"<< endl;
    double firstNumber(0);
    double secondNumber(0);
    char mathOperator('\0');
    cin >> firstNumber >> secondNumber >> mathOperator;


    //Logic

    double result(0);
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