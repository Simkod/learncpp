//Solve quadratic equations

#include <iostream>

using namespace std;

int main()
{
    double a(0);
    double b(0);
    double c(0);

    //user input

    cin >> a;
    cin >> b;
    cin >> c;

    bool solvableR(true);

    //check if solvable
    if (pow(b, 2) - 4 * a*c < 0)
    {
        solvableR = false;
    }
    
    if (-b + sqrt(pow(b, 2) - 4 * a*c) == 0)
    {
        solvableR = false;
    }

    if (-b - sqrt(pow(b, 2) - 4 * a*c) == 0)
    {
        solvableR = false;
    }

    //calculate x1 and x2
    if (a == 0)
    {
        double x = (-b) / c;
        cout << "x: " << x << endl;
    }
        
    if (solvableR)
    {
        double x1(0);
        double x2(0);

        //double powtest = pow(b, 2);
        //double underVans = powtest - 4 * a*c;
        //double sqrttest = sqrt(underVans);
        //double divisionTest = (-b + sqrttest) / (2 * a);

        x1 = (-b + sqrt(pow(b, 2) - 4 * a*c)) / (2 * a);
        x2 = (-b - sqrt(pow(b, 2) - 4 * a*c)) / 2 * a;

        cout << "x1: " << x1 << endl;
        cout << "x1: " << x2 << endl;
    }
    else
    {
        cout << "Not solvable on Rational numbers set." << endl;
    }
    system("pause");
}