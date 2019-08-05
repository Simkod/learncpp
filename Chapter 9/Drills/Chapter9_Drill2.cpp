//Chapter 9 - Drill 2
//This drill simply involves getting the sequence of versions of Date to work.
//For each version define a Date called today initialized to June 25, 1978.
//Then, define a Date called tomorrow and give it a value by copying today into it and increasing its day by one using add_day().
//Finally, output today and tomorrow using a << defined as in §9.8.

//Your check for a valid date may be very simple.
//Feel free to ignore leap years.
//However, don’t accept a month that is not in the[1, 12] range or day of the month that is not in the[1, 31] range.

//Test each version with at least one invalid date(e.g., 2004, 13, –5).

#include "std_lib_facilities.h"
#include <assert.h>

const int minDay(0);
const int maxDay(31);
const int minMonth(0);
const int maxMonth(12);
const int minYear(1900);
const int maxYear(2100);

struct Date
{
    int year;       
    int month;    
    int day;  

    Date(int inYear, int inMonth, int inDay)
    {
        year = inYear;
        month = inMonth;
        day = inDay;

        isDateValid();
    }

    bool isDayValid(int& day)
    {
        if (day < minDay || day > maxDay)
        {
            assert(false);
            return false;
        }
        else
        {
            return true;
        }
    }

    bool isMonthValid(int& month)
    {
        if (month < minMonth || month > maxMonth)
        {
            assert(false);
            return false;
        }
        else
        {
            return true;
        }
    }

    bool isYearValid(int& year)
    {
        if (year < minYear || year > maxYear)
        {
            assert(false);
            return false;
        }
        else
        {
            return true;
        }
    }

    bool isDateValid()
    {
        if (isDayValid(day) && isMonthValid(month) && isYearValid(year))
        {
            return true;
        }
        else
        {
            cout << "Date Invalid." << endl;
            assert(false);
            return false;
        }
    }


    void addOneYear()
    {
        if (year == maxYear)
        {
            cout << "You reached the maximum year." << endl;
        }
        else
        {
            int temp = year;
            ++temp;

            if (isYearValid(temp))
            {
                year = temp;
            }
            else
            {
                cout << "Year invalid, adding year failed" << endl;
            }
        }

        if (!isDateValid())
        {
            cout << "Invalid Date, something is wrong" << endl;
        }
    }

    void addOneMonth()
    {
        if (month == maxMonth)
        {
            month = 1;
            addOneYear();
        }
        else
        {
            int temp = month;
            ++temp;

            if (isMonthValid(temp))
            {
                month = temp;
            }
            else
            {
                cout << "Month invalid, adding month failed" << endl;
            }
        }

        if (!isDateValid())
        {
            cout << "Invalid Date, something is wrong" << endl;
        }
    }

    void addOneDay()
    {
        if (day == maxDay)
        {
            day = 1;
            addOneMonth();
        }
        else
        {
            int temp = day;
            ++temp;

            if (isDayValid(temp))
            {
                day = temp;
            }
            else
            {
                cout << "Day invalid, adding day failed" << endl;
            }
        }

        if (!isDateValid())
        {
            cout << "Invalid Date, something is wrong" << endl;
        }
    }

};
   
ostream& operator<<(ostream& os,const Date& date)
{
    return os << '(' << date.year
        << ',' << date.month
        << ',' << date.day << ')';
}

int main()
{
    Date today(1978, 6, 25);

    Date tomorrow = today;

    tomorrow.addOneDay();

    cout << "Today: " <<  today << endl;
    cout << "Tomorrow: " << tomorrow << endl;

    system("pause");
}