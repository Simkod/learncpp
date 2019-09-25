// Chapter 9 Exercise 12

// Change the representation of a Date to be the number of days since January 1, 1970 (known as day 0),
// represented as a long int, and reimplement the functions from §9.8.
// Be sure to reject dates outside the range we can represent that way
// (feel free to reject days before day 0, i.e., no negative days).

#include "Date.h"

void main()
{
    Date baseDate = Date(1970, jan, 1);
    Date* base = &baseDate;

    Date myDate = Date(1971, sep, 25, base);

    unsigned long int dayssinceBaseDate = myDate.getDaysSinceBaseDate();

    system("pause");
}