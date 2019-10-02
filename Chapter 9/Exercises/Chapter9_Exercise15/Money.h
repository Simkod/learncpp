#pragma once

#ifndef MONEY_H
#define MONEY_H

#include <vector>
#include <map>

enum Currency
{
    CHF,
    EUR,
    HUF
};

enum ChangeWhatToWhat
{
    CHFtoEUR = 0,
    CHFtoHUF = 1,
    EURtoCHF = 2,
    EURtoHUF = 3,
    HUFtoCHF = 4,
    HUFtoEUR = 5
};

class Money
{
public:
    Money(float amount, std::string currency);
    Money(float amount, Currency currency);
    ~Money();

    //Money operator*(Money& rhs);
    //Money operator/(Money& rhs);
    Money operator+(Money& rhs);
    Money operator-(Money& rhs);
    bool operator==(Money& rhs);
       
public:
    void diplayMoney() const;
    Currency getcurrency() const;
    void changeTo(Currency newCurrency);
    float getAmount() const;

private:
    Currency translateCurrency(std::string currency);
    void initChangingCourses();
    void setCurrency(Currency newCurrency);
    void setAmount(float newAmount);
    ChangeWhatToWhat getChangeWhatToWhat(Currency currency1, Currency currency2) const;
    float getChangeCourse(ChangeWhatToWhat whatToWhat);
    void setCurrencyChangingCourses(std::map<ChangeWhatToWhat, float> courses);


private:
    float m_amount;
    Currency m_currency;
    std::map<ChangeWhatToWhat, float> m_currencyChangingCourses;
};

#endif // MONEY_H