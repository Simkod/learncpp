// Chapter 9 Exercise 13

// Design and implement a rational number class, Rational.
// A rational number has two parts: a numerator and a denominator, for example, 5/6 (five-sixths, also known as approximately 0.83333).
// Provide assignment, addition, subtraction, multiplication, division, and equality operators.
// Also, provide a conversion to double. 
// Why would people want to use a Rational class ?
//  Because the basic operations on Rational Numbers can not be used without a class. Also storing a rational number as a double can cause trouble when we want to show it according to the definition (p/q).

#include "Rational.h"
#include <process.h>

void main()
{
    Rational num1(4, 65);
    Rational num2(2, 2);

    //Test *
    Rational num3 = num1 * num2;
    //Test /
    Rational num4 = num1 / num2;
    //Test +
    Rational num5 = num1 + num2;
    //Test -
    Rational num6 = num1 - num2;
    //Test ==
    bool equal = (num1 == num2);
    //Test conversion to double
    double valueOfRational = num1.getRationalAsDouble();

    system("pause");
}