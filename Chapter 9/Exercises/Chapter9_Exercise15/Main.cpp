
// Chapter 9 Exercise 15

// Refine the Money class by adding a currency(given as a constructor argument). 
// Accept a floating-point initializer as long as it can be exactly represented as a long int.
// Don’t accept illegal operations.
// For example, Money*Money doesn’t make sense,
// and USD1.23 + DKK5.00 makes sense only if you provide a conversion table
// defining the conversion factor between U.S.dollars(USD) and Danish kroner(DKK).

#include "Money.h"

int main()
{
    Money myMoney(6, "huf");
    Money yourMoney(6, "eur");

    Money moneyPlus = myMoney + yourMoney;

    moneyPlus.diplayMoney();

    system("pause");
}