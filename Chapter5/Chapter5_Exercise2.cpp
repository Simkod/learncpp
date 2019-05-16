#include "std_lib_facilities.h"

double ctok(double celsius)                   // converts Celsius to Kelvin
{
    double kelvin = celsius + 273.15;
    return kelvin;
}

int main()
{
    double c = 0;                      // declare input variable
    cin >> c;                          // retrieve temperature to input variable
    double k = ctok(c);                // convert temperature
    cout << k << '/n';                 // print out temperature

    system("Pause");

}