// Chapter 10 - Exercise 7

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
    std::cout << "Enter first number: ";
    std::cin >> value;
    RomanNumber newRoman(value);
    std::cout << "\n";
    std::cout << newRoman.getValue() << " equals " << "Roman " << newRoman.getValueInRomanRepresentation() << "\n";
    std::cout << "\n";

    std::cout << "Enter second number: ";
    std::cin >> value;
    RomanNumber otherRoman(value);
    std::cout << "\n";
    std::cout << otherRoman.getValue() << " equals " << "Roman " << otherRoman.getValueInRomanRepresentation() << "\n";
    std::cout << "\n";

    RomanNumber addedUpRoman = newRoman + otherRoman;
    std::cout << newRoman.getValue() << " + " << otherRoman.getValue() << " = " << addedUpRoman.getValue() << "\n";
    std::cout << newRoman.getValueInRomanRepresentation() << " + " << otherRoman.getValueInRomanRepresentation() << " = " << addedUpRoman.getValueInRomanRepresentation() << "\n";
    std::cout << "\n";

    system("pause");
}