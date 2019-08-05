//Chapter 9 - Drill 2
//This drill simply involves getting the sequence of versions of Date to work.
//For each version define a Date called today initialized to June 25, 1978.
//Then, define a Date called tomorrow and give it a value by copying today into it and increasing its day by one using add_day().
//Finally, output today and tomorrow using a << defined as in �9.8.

//Your check for a valid date may be very simple.
//Feel free to ignore leap years.
//However, don�t accept a month that is not in the[1, 12] range or day of the month that is not in the[1, 31] range.

//Test each version with at least one invalid date(e.g., 2004, 13, �5).

#include "Date.h"
#include <process.h>

int main()
{
    Date today(1978, 6, 25);

    Date tomorrow = today;

    tomorrow.addOneDay();

    today.printDate();
    tomorrow.printDate();

    system("pause");
}