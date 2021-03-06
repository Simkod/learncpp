#include "Date.h"

#include "std_lib_facilities.h"

#include <assert.h>




Date::Date(int inYear, Month inMonth, int inDay)
    : m_year(inYear)
    , m_month(inMonth)
    , m_day(inDay)
    , m_minDay(0)
    , m_maxDay(31)
    , m_minMonth(Month::jan)
    , m_maxMonth(Month::dec)
    , m_minYear(1900)
    , m_maxYear(2100)
{
    isDateValid();
}

Date::~Date()
{
}



bool Date::isDayValid(const int& day) const
{
    if (day < m_minDay || day > m_maxDay)
    {
        assert(false);
        return false;
    }
    else
    {
        return true;
    }
}

bool Date::isMonthValid(const Month& month) const
{
    if (month < m_minMonth || month > m_maxMonth)
    {
        assert(false);
        return false;
    }
    else
    {
        return true;
    }
}

bool Date::isYearValid(const int& year) const
{
    if (year < m_minYear || year > m_maxYear)
    {
        assert(false);
        return false;
    }
    else
    {
        return true;
    }
}

bool Date::isDateValid() const
{
    if (isDayValid(m_day) && isMonthValid(m_month) && isYearValid(m_year))
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


void Date::addOneYear()
{
    if (m_year == m_maxYear)
    {
        cout << "You reached the maximum year." << endl;
    }
    else
    {
        int temp = m_year;
        ++temp;

        if (isYearValid(temp))
        {
            m_year = temp;
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

void Date::addOneMonth()
{
    if (m_month == m_maxMonth)
    {
        m_month = Month::jan;
        addOneYear();
    }
    else
    {
        Month temp = m_month;
        temp = Month(temp+1);

        if (isMonthValid(temp))
        {
            m_month = temp;
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

void Date::addOneDay()
{
    if (m_day == m_maxDay)
    {
        m_day = 1;
        addOneMonth();
    }
    else
    {
        int temp = m_day;
        ++temp;

        if (isDayValid(temp))
        {
            m_day = temp;
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

const int& Date::getYear() const
{
    return m_year;
}

const int Date::getMonth() const
{
    const int month = (int)m_month;
    return month;
}

const int& Date::getDay() const
{
    return m_day;
}

void Date::printDate()
{
    cout << this->getYear() << "." << this->getMonth() << "." << this->getDay() << endl;
}
