#include "Date.h"

#include "std_lib_facilities.h"

#include <assert.h>

Date::Date(int inYear, Month inMonth, int inDay, Date* baseDate)
    : m_year(inYear)
    , m_month(inMonth)
    , m_day(inDay)
    , m_baseDate(baseDate)
    , m_minMonth(Month::jan)
    , m_maxMonth(Month::dec)
    , m_minYear(1970)
    , m_maxYear(9999)
{
    if (baseDate)
    {
        calculateNewMaxYearFromBaseDate();
    }

    initMonthCapacities(isLeapYear());
    isDateValid();

    if (baseDate)
    {
        calculateDaysSinceBaseDate();
    }

}

Date::~Date()
{
}

Date::Date(const Date& date)
    : m_year(date.getYear())
    , m_month(static_cast<Month>(date.getMonth()))
    , m_day(date.getDay())
    , m_baseDate(date.getBaseDate())
    , m_monthCapacities(date.getMonthCapacities())
    , m_minMonth(Month::jan)
    , m_maxMonth(Month::dec)
    , m_minYear(1970)
    , m_maxYear(date.getMaxYear())
{
    isDateValid();
}

bool Date::isDayValid(const int& day) const
{
    int numberofDaysInMonth = getNumberofDaysInMonth(m_month);

    if (day < 1 || day > numberofDaysInMonth)
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
        assert(false && "Invalid Month");
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
        assert(false && "Invalid Year");
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

std::string Date::getMonthAsString() const
{
    std::string month;

    if (m_month == Month::jan)
    {
        month = "jan";
    }
    else if (m_month == Month::feb)
    {
        month = "feb";
    }
    else if (m_month == Month::mar)
    {
        month = "mar";
    }
    else if (m_month == Month::apr)
    {
        month = "apr";
    }
    else if (m_month == Month::may)
    {
        month = "may";
    }
    else if (m_month == Month::jun)
    {
        month = "jun";
    }
    else if (m_month == Month::jul)
    {
        month = "jul";
    }
    else if (m_month == Month::aug)
    {
        month = "aug";
    }
    else if (m_month == Month::sep)
    {
        month = "sep";
    }
    else if (m_month == Month::oct)
    {
        month = "oct";
    }
    else if (m_month == Month::nov)
    {
        month = "nov";
    }
    else if (m_month == Month::dec)
    {
        month = "dec";
    }

    return month;
}

int Date::getNumberofDaysInMonth(Month month) const
{
    int numberofDaysInMonth = m_monthCapacities.find(month)->second;
    return numberofDaysInMonth;
}

void Date::calculateDaysSinceBaseDate()
{
    unsigned long int daysSinceBaseDate(0);
    for (int yearIt = m_baseDate->getYear(); yearIt < m_year; ++yearIt)
    {
        if (isLeapYear(yearIt))
        {
            daysSinceBaseDate += 366;
        }
        else
        {
            daysSinceBaseDate += 365;
        }
    }
    daysSinceBaseDate += getDaysUntilDate();

    m_daysSinceBaseDate = daysSinceBaseDate;
}

void Date::calculateNewMaxYearFromBaseDate()
{
    int maxYearsFromBaseDate = LONG_MAX / 366;
    m_maxYear = m_baseDate->getYear() + maxYearsFromBaseDate;
}

int reNumberMonthForWeekDayCalculation(Month month)
{
    int max = 12;
    if (month <= 10 && month > 2)
    {
        return static_cast<Month>(month - 2);
    }
    else if (month == jan)
    {
        return static_cast<Month>(11);
    }
    else if (month == feb)
    {
        return static_cast<Month>(12);
    }
}

DayName Date::whichDayOfTheWeek() const
{
    //https://cs.uwaterloo.ca/~alopez-o/math-faq/node73.html

    int day = m_day;
    int century = m_year / 100; //first two digits of year
    int lastTwoDigitOfYear = m_year % 100;
    int monthReCalc = reNumberMonthForWeekDayCalculation(m_month);

    int rawDay = (day + floor(2.6 * monthReCalc - 0.2) - 2*century + lastTwoDigitOfYear + floor((lastTwoDigitOfYear / 4)) + floor((century / 4)));
    int whichDay = rawDay % 7;

    DayName dayName = static_cast<DayName>(whichDay);
    
    return dayName;
}

Date Date::nextWorkDay() const
{
    Date nextWorkingDay(*this);

    nextWorkingDay.addOneDay();

    while (!nextWorkingDay.isWorkDay())
    {
        nextWorkingDay.addOneDay();
    }
    return nextWorkingDay;
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
            initMonthCapacities(isLeapYear()); //year changed -> update necessary
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
        temp = Month(temp + 1);

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
    if (m_day == getNumberofDaysInMonth(m_month))
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

bool Date::isWorkDay() const
{
    DayName thisDay = whichDayOfTheWeek();
    if (thisDay == Monday || thisDay == Tuesday || thisDay == Wednesday || thisDay == Thursday || thisDay == Friday)
    {
        return true;
    }
    return false;
}

std::string Date::getDateAsString() const
{
    std::string date;

    date += std::to_string(m_day);
    date += ".";
    date += getMonthAsString();
    date += ".";
    date += std::to_string(m_year);

    return date;
}

void Date::printDate()
{
    cout << this->getYear() << "." << this->getMonth() << "." << this->getDay() << endl;
}

bool Date::isLeapYear() const
{
    //Every year that is exactly divisible by four is a leap year,
    //except for years that are exactly divisible by 100,
    //but these centurial years are leap years if they are exactly divisible by 400.
    //For example, the years 1700, 1800, and 1900 are not leap years, but the years 1600 and 2000 are.

    if (m_year % 4 == 0) 
    {
        if (m_year % 100 == 0)
        {
            if (m_year % 400 == 0)
            {
                return true;
            }
            return false;
        }        
        return true;
    }
    return false;
}

bool Date::isLeapYear(int year) const
{
    //Every year that is exactly divisible by four is a leap year,
    //except for years that are exactly divisible by 100,
    //but these centurial years are leap years if they are exactly divisible by 400.
    //For example, the years 1700, 1800, and 1900 are not leap years, but the years 1600 and 2000 are.

    if (year % 4 == 0)
    {
        if (year % 100 == 0)
        {
            if (year % 400 == 0)
            {
                return true;
            }
            return false;
        }
        return true;
    }
    return false;
}

int Date::getDaysUntilDate() const
{
    int numberOfDays(0);
    for (std::map<Month, int>::const_iterator monthIt = m_monthCapacities.begin(); monthIt->first != m_month; ++monthIt)
    {
        numberOfDays += monthIt->second;
    }
    numberOfDays += m_day;
    return numberOfDays;
}

int Date::getWeekOfYear() const
{
    int numberOfWeeks = (getDaysUntilDate() / 7) + 1;
         
    return numberOfWeeks;
}

Date * Date::getBaseDate() const
{
    return m_baseDate;
}

unsigned long int Date::getDaysSinceBaseDate() const
{
    return m_daysSinceBaseDate;
}

int Date::getMaxYear() const
{
    return m_maxYear;
}

void Date::initMonthCapacities(bool isLeapYear)
{
    m_monthCapacities.clear();

    for (int monthIndex = 1; monthIndex < 13; ++monthIndex)
    {
        int numberOfDaysInMonth(0);
        Month month = static_cast<Month>(monthIndex);
        if (month == jan || month == mar || month == may || month == jul || month == aug || month == Month::oct || month == Month::dec)
        {
            numberOfDaysInMonth = 31;
        }
        if (month == apr || month == jun || month == sep || month == nov)
        {
            numberOfDaysInMonth = 30;
        }
        if (month == feb)
        {
            if (isLeapYear)
            {
                numberOfDaysInMonth = 29;
            }
            else
            {
                numberOfDaysInMonth = 28;
            }
        }
        std::pair<Month, int> monthDay = std::make_pair(month, numberOfDaysInMonth);
        m_monthCapacities.insert(monthDay);
    }

    //check methods
    assert(m_monthCapacities.size() == 12 && "Number of months in Months day capacities is not correct.");

    int sumOfDays(0);
    for (std::map<Month, int>::const_iterator monthIt = m_monthCapacities.begin(); monthIt != m_monthCapacities.end(); ++monthIt)
    {
        sumOfDays += monthIt->second;
    }
    if (!isLeapYear)
    {
        assert(sumOfDays == 365 && "Number of Months day capacities is not correct.");
    }
    else
    {
        assert(sumOfDays == 366 && "Number of Months day capacities is not correct.");
    }
}

std::map<Month, int> Date::getMonthCapacities() const
{
    return m_monthCapacities;
}
