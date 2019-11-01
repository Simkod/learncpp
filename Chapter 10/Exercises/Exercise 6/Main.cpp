// Chapter 10 - Exercise 6

// Define a Roman_int class for holding Roman numerals(as ints) with a << and >>.
// Provide Roman_int with an as_int() member that returns the int value,
// so that if r is a Roman_int, we can write cout << "Roman" << r << " equals " << r.as_int() << '\n';.

#include "RomanNumber.h"
#include "UnitTest.h"

std::ostream& operator<<(std::ostream& os, RomanNumber& roman)
{
    os << roman.getValue() << "\n";
    return os;
}

int main()
{
    UnitTest tester;
    tester.runUnitTests();
    
    int value;
    std::cin >> value;

    RomanNumber newRoman(value);

    std::cout << "Roman " << newRoman.getValueInRomanRepresentation() << " equals " << newRoman << "\n";

    system("pause");
}