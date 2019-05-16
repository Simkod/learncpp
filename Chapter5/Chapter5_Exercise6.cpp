//program that converts from Celsius to Fahrenheit and from Fahrenheit to Celsius
// Use estimation

#include "std_lib_facilities.h"

double ctof(double celsius)                   // converts Celsius to Fahrenheit
{
    double fahrenheit = 9.0/5.0 * celsius + 32 ;

    //if (fahrenheit < 0) error("That low temperature is physically not possible.");

    return fahrenheit;
}
double ftoc(double fahrenheit)                   // converts Fahrenheit to Celsius
{
    double celsius  = (fahrenheit - 32)  * 5.0 / 9.0;
    //if (fahrenheit < -273.15) error("That low temperature is physically not possible.");

    return celsius;
}


int main()
{

    cout << "You want to convert Fahrenheit to Celsius (enter 'F') or Celsius to Fahrenheit? (enter 'C')\n";
    char userInput;
    cin >> userInput;

    cout << "Enter your degree: ";
    double userDegree = 0;
    cin >> userDegree;

    double convertedDegree(0);

    if (userInput == 'F')
    {
        convertedDegree = ftoc(userDegree);
    }
    else if (userInput == 'C')
    {
        convertedDegree = ctof(userDegree);
    }
    else
    {
        cout << "Input error...";
    }
                                       
    cout << setprecision(4) <<  convertedDegree << endl;                 

    system("Pause");

}