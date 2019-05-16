#include "std_lib_facilities.h"

double ctok(double celsius)                   // converts Celsius to Kelvin
{

    double kelvin = celsius + 273.15;

    if (kelvin < 0) error("That low temperature is physically not possible.");

    return kelvin;
}

int main()
{
    double c = 0;                      
    cin >> c;                          
    double k = ctok(c);

                                       
    cout << k << '/n';                 

    system("Pause");

}