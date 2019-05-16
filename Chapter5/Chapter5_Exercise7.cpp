//Solve quadratic equations

#include <iostream>

using namespace std;

bool preConditions(double a, double b, double c)
{
    if (pow(b, 2) - 4 * a*c < 0
        || -b + sqrt(pow(b, 2) - 4 * a*c) == 0
        || -b - sqrt(pow(b, 2) - 4 * a*c) == 0)
    {
        return false;
    }
    return true;
}

int main()
{
    //user input
    //pre conditions
    //logic
    //output
    
    double a(0);
    double b(0);
    double c(0);

    cin >> a;
    cin >> b;
    cin >> c;

    bool solvable = preConditions(a, b, c);

    double x1(INT_MIN);
    double x2(INT_MIN);

    //calculate x1 and x2
    if (solvable)
    {
        if (a == 0)
        {
            x1 = (-b) / c;
        }
        else
        {
            x1 = (-b + sqrt(pow(b, 2) - 4 * a*c)) / (2 * a);
            x2 = (-b - sqrt(pow(b, 2) - 4 * a*c)) / 2 * a;
        }
    }

    //output
    if (x1 != INT_MIN && x2 != INT_MIN && solvable)
    {
        cout << "x1: " << x1 << endl;
        cout << "x2: " << x2 << endl;
    }
    else if (x2 == INT_MIN)
    {
        cout << "x1: " << x1 << endl;
    }
    else if (!solvable)
    {
        cout << "Not solvable on Rational numbers set." << endl;
    }
    else
    {
        cout << "Unhandled error." << endl;
    }

 
  
    system("pause");
}