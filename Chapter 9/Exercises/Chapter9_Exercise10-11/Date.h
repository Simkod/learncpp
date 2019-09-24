#pragma once

#include <string>
#include <map>

#ifndef DATE_H
#define DATE_H

enum Month
{
    jan = 1, feb , mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

enum DayName
{
    Monday = 1,
    Tuesday = 2,
    Wednesday = 3,
    Thursday = 4,
    Friday = 5,
    Saturday = 6,
    Sunday = 0,
    Unknown = INT_MAX
};

class Date
{
public:
    Date(int inYear, Month inMonth, int inDay);
    ~Date();
    Date(const Date &date); 

    void addOneYear();
    void addOneMonth();
    void addOneDay();

    const int& getYear() const;
    const int getMonth() const;
    const int& getDay() const;

    std::string getDateAsString() const;
    void printDate();

    DayName whichDayOfTheWeek() const;
    bool isWorkDay()const;
    Date nextWorkDay() const;
    bool isLeapYear() const;

    int getDaysUntilDate() const;
    int getWeekOfYear() const;

private:
    void initMonthCapacities(bool isLeapYear);
    std::map<Month, int> getMonthCapacities() const;

    bool isDayValid(const int& day) const;
    bool isMonthValid(const Month& month) const;
    bool isYearValid(const int& year) const;
    bool isDateValid() const;

    std::string getMonthAsString() const;

    int getNumberofDaysInMonth(Month month) const;

private:
    int m_year;
    Month m_month;
    int m_day;

    std::map<Month, int> m_monthCapacities;

    const int m_minMonth;
    const int m_maxMonth;
    const int m_minYear;
    const int m_maxYear;
};

#endif // DATE_H