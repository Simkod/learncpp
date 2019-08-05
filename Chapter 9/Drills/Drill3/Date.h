#pragma once

class Date
{
public:
    Date(int inYear, int inMonth, int inDay);
    ~Date();

    void addOneYear();
    void addOneMonth();
    void addOneDay();

    const int& getYear() const;
    const int& getMonth() const;
    const int& getDay() const;

    void printDate();

private:
    bool isDayValid(const int& day) const;
    bool isMonthValid(const int& month) const;
    bool isYearValid(const int& year) const;
    bool isDateValid() const;

private:
    int m_year;
    int m_month;
    int m_day;

    const int m_minDay;
    const int m_maxDay;
    const int m_minMonth;
    const int m_maxMonth;
    const int m_minYear;
    const int m_maxYear;
};
