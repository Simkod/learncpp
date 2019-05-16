#include "std_lib_facilities.h"

double ctok(double celsius)                   // converts Celsius to Kelvin
{
    double kelvin = celsius + 273.15;
    return kelvin;
}

int main()
{
    double c = 0;                      
    cin >> c;                          
    double k = ctok(c);
    if (k < 0) error("That low temperature is physically not possible.");
                                       
    cout << k << '/n';                 

    system("Pause");

}