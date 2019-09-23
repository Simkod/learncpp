#pragma once

#include <string>

#ifndef DATE_H
#define DATE_H

enum Month
{
    jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec,
    Unknown = INT_MAX
};

class Date
{
public:
    Date();
    Date(int inYear, Month inMonth, int inDay);
    ~Date();

    void addOneYear();
    void addOneMonth();
    void addOneDay();

    const int& getYear() const;
    const int getMonth() const;
    const int& getDay() const;

    std::string getDateAsString() const;

    void printDate();

private:
    bool isDayValid(const int& day) const;
    bool isMonthValid(const Month& month) const;
    bool isYearValid(const int& year) const;
    bool isDateValid() const;

    std::string getMonthAsString() const;

private:
    int m_year;
    Month m_month;
    int m_day;

    const int m_minDay;
    const int m_maxDay;
    const int m_minMonth;
    const int m_maxMonth;
    const int m_minYear;
    const int m_maxYear;
};

#endif // !DATE_H