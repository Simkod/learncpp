#include "Money.h"
#include <vector>
#include <iostream>
#include <algorithm>

Money::Money(float amount, std::string currency)
    : m_amount(amount)
    , m_currency(translateCurrency(currency))
{
    initChangingCourses();
}

Money::Money(float amount, Currency currency)
    : m_amount(amount)
    , m_currency(currency)
{
    initChangingCourses();
}

Money::~Money()
{
}

//Money Money::operator*(Money & rhs)
//{
//    if (m_currency != rhs.getcurrency())
//    {
//        rhs.changeTo(m_currency);
//    }
//    
//    float newAmount = m_amount * rhs.getAmount();
//
//    Money newMoney(newAmount, m_currency);
//
//    return newMoney;
//}
//
//Money Money::operator/(Money & rhs)
//{
//    if (m_currency != rhs.getcurrency())
//    {
//        rhs.changeTo(m_currency);
//    }
//
//    float newAmount = m_amount / rhs.getAmount();
//
//    Money newMoney(newAmount, m_currency);
//
//    return newMoney;
//}

Money Money::operator+(Money& rhs)
{
    if (m_currency != rhs.getcurrency())
    {
        rhs.changeTo(m_currency);
    }

    float newAmount = m_amount + rhs.getAmount();

    Money newMoney(newAmount, m_currency);

    return newMoney;
}

Money Money::operator-(Money & rhs)
{
    if (m_currency != rhs.getcurrency())
    {
        rhs.changeTo(m_currency);
    }

    float newAmount = m_amount - rhs.getAmount();

    Money newMoney(newAmount, m_currency);

    return newMoney;
}

bool Money::operator==(Money & rhs)
{
    if (m_currency != rhs.getAmount())
    {
        return false;
    }
    else if (m_amount != rhs.getAmount())
    {
        return false;
    }
}

void Money::diplayMoney() const
{
    std::cout << "Thats " << m_amount;
    std::cout << "\n";
}

Currency Money::getcurrency() const
{
    return m_currency;
}

void Money::changeTo(Currency newCurrency)
{
    ChangeWhatToWhat changeWhatToWhat = getChangeWhatToWhat(m_currency, newCurrency);
    double changingCourse = getChangeCourse(changeWhatToWhat);

    setAmount(changingCourse*m_amount);

    setCurrency(newCurrency);
}

float Money::getAmount() const
{
    return m_amount;
}

Currency Money::translateCurrency(std::string currency)
{
    Currency result;

    if (currency.size() != 3)
    {
        std::cout << "fail in currency lenght. It must be 3 digits";
    }
    else
    {
        transform(currency.begin(), currency.end(), currency.begin(), ::tolower);

        if (currency == "chf")
        {
            result = CHF;
        }
        if (currency == "eur")
        {
            result = EUR;
        }
        if (currency == "huf")
        {
            result = HUF;
        }
    }
    return result;
}

void Money::initChangingCourses()
{
    std::map<ChangeWhatToWhat, float> changingCourses;
    std::pair<ChangeWhatToWhat, float> chfToEur = std::make_pair<ChangeWhatToWhat, double>(CHFtoEUR, 1.1);
    changingCourses.insert(chfToEur);

    std::pair<ChangeWhatToWhat, float> chfToHuf = std::make_pair<ChangeWhatToWhat, double>(CHFtoHUF, 308);
    changingCourses.insert(chfToHuf);

    std::pair<ChangeWhatToWhat, float> eurToChf = std::make_pair<ChangeWhatToWhat, double>(EURtoCHF, 0.9);
    changingCourses.insert(eurToChf);

    std::pair<ChangeWhatToWhat, float> eurToHuf = std::make_pair<ChangeWhatToWhat, double>(EURtoHUF, 335);
    changingCourses.insert(eurToHuf);

    std::pair<ChangeWhatToWhat, float> hufToChf = std::make_pair<ChangeWhatToWhat, double>(HUFtoCHF, 0.003);
    changingCourses.insert(chfToEur);

    std::pair<ChangeWhatToWhat, float> hufToEur = std::make_pair<ChangeWhatToWhat, double>(HUFtoEUR, 0.003);
    changingCourses.insert(hufToEur);

    setCurrencyChangingCourses(changingCourses);
}

void Money::setCurrency(Currency newCurrency)
{
    m_currency = newCurrency;
}

void Money::setAmount(float newAmount)
{
    m_amount = newAmount;
}

ChangeWhatToWhat Money::getChangeWhatToWhat(Currency currency1, Currency currency2) const
{
    
    if (currency1 == CHF)
    {
        if (currency2 == EUR)
        {
            return CHFtoEUR;
        }
        if (currency2 == HUF)
        {
            return CHFtoHUF;
        }
    }
    else if (currency1 == EUR)
    {
        if (currency2 == CHF)
        {
            return EURtoCHF;
        }
        if (currency2 == HUF)
        {
            return EURtoHUF;
        }
    }
    else if (currency1 == HUF)
    {
        if (currency2 == CHF)
        {
            return HUFtoCHF;
        }
        if (currency2 == EUR)
        {
            return HUFtoCHF;
        }
    }

    return ChangeWhatToWhat();
}

float Money::getChangeCourse(ChangeWhatToWhat whatToWhat)
{
    return m_currencyChangingCourses.find(whatToWhat)->second;
}

void Money::setCurrencyChangingCourses(std::map<ChangeWhatToWhat, float> courses)
{
    m_currencyChangingCourses = courses;
}
