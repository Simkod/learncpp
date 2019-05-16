#include "std_lib_facilities.h"

double ctok(double celsius)                   // converts Celsius to Kelvin
{
    double kelvin = celsius + 273.15;

    if (kelvin < 0) error("That low temperature is physically not possible.");

    return kelvin;
}
double ktoc(double kelvin)                   // converts Kelvin to Celsius
{
    double celsius  = kelvin - 273.15;

    if (celsius < -273.15) error("That low temperature is physically not possible.");

    return celsius;
}


int main()
{

    cout << "You want to convert Kelvin to Celsius (enter 'K') or Celsius to Kelvin? (enter 'C')\n";
    char userInput;
    cin >> userInput;

    cout << "Enter your degree: ";
    double userDegree = 0;
    cin >> userDegree;

    double convertedDegree(0);

    if (userInput == 'K')
    {
        convertedDegree = ktoc(userDegree);
    }
    else if (userInput == 'C')
    {
        convertedDegree = ctok(userDegree);
    }
    else
    {
        cout << "Input error...";
    }
                                       
    cout << convertedDegree << '/n';                 

    system("Pause");

}