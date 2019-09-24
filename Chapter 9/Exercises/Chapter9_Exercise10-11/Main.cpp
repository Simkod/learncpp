// Chapter 9 Exercise 10 &  11

// Exercise 10:
// Implement leapyear() from §9.8.

// Exercise 11:
// Design and implement a set of useful helper functions for the Date class.
// next_workday() (Assume that any day that is not a Saturday or a Sunday is a workday)
// week_of_year() (assume that week 1 is the week with January 1 in it and that the first day of a week is a Sunday).

#include "Date.h"

void main()
{
    Date myDate = Date(2019, sep, 24);
    DayName currentday = myDate.whichDayOfTheWeek();
    int myDays = myDate.getDaysUntilDate();
    int myWeeks = myDate.getWeekOfYear();

    Date nextWorkDay = myDate.nextWorkDay();
    DayName nextworkday = nextWorkDay.whichDayOfTheWeek();

    system("pause");
}