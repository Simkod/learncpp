#include "Rational.h"
#include <assert.h>

Rational::Rational(int numerator, int denominator)
    : m_numerator(numerator)
{
    if (denominator == 0)
    {
        assert(denominator && "Denominator can't be 0.");
    }
    else
    {
        setDenominator(denominator);
    }
    simplify();
}

Rational::~Rational()
{
}

Rational Rational::operator*(Rational & rhs)
{
    int newNumerator = m_numerator * rhs.getNumerator();
    int newDenominator = m_denominator * rhs.getDenominator();

    Rational newRational(newNumerator, newDenominator);
    newRational.simplify();
    
    return newRational;
}

Rational Rational::operator/(Rational & rhs)
{
    int newNumerator = m_numerator * rhs.getDenominator();
    int newDenominator = m_denominator * rhs.getNumerator();

    Rational newRational(newNumerator, newDenominator);
    newRational.simplify();

    return newRational;
}

Rational Rational::operator+(Rational& rhs)
{
    // Calculate LCM for new Denominator
    int newDenominator = calculateLeastCommonMultiple(m_denominator, rhs.getDenominator());

    // New Nominator
    int numerator1Multipler = newDenominator / m_denominator;
    int numerator2Multipler = newDenominator / rhs.getDenominator();
    int newNumerator = (m_numerator * numerator1Multipler) + (rhs.getNumerator() * numerator2Multipler);

    Rational newRational(newNumerator, newDenominator);
    newRational.simplify();

    return newRational;
}

Rational Rational::operator-(Rational & rhs)
{
    // Calculate LCM for new Denominator
    int newDenominator = calculateLeastCommonMultiple(m_denominator, rhs.getDenominator());

    // New Nominator
    int numerator1Multipler = newDenominator / m_denominator;
    int numerator2Multipler = newDenominator / rhs.getDenominator();
    int newNumerator = (m_numerator * numerator1Multipler) - (rhs.getNumerator() * numerator2Multipler);

    Rational newRational(newNumerator, newDenominator);
    newRational.simplify();

    return newRational;
}

bool Rational::operator==(Rational & rhs)
{
    if (m_numerator == rhs.getNumerator() && m_denominator == rhs.getDenominator())
    {
        return true;
    }
    else
    {
        return false;
    }

}

int Rational::getNumerator() const
{
    return m_numerator;
}

void Rational::simplify()
{
    if (m_numerator == 0)
    {
        return;
    }
    else
    {
        if (m_denominator % m_numerator == 0)
        {
            setDenominator(m_denominator / m_numerator);
            setNumerator(m_numerator / m_numerator);
        }
        else
        {
            int greatestCommonDivisor = calculateGreatestCommonDivisor(m_numerator, m_denominator);
            setNumerator(m_numerator / greatestCommonDivisor);
            setDenominator(m_denominator / greatestCommonDivisor);
        }
    }
}

void Rational::setDenominator(int denominator)
{
    m_denominator = denominator;
}

void Rational::setNumerator(int numerator)
{
    m_numerator = numerator;
}

int Rational::getDenominator() const
{
    return m_denominator;
}

double Rational::getRationalAsDouble() const
{
    double rational = (double)m_numerator / (double)m_denominator;
    return rational;
}

int Rational::calculateLeastCommonMultiple(int number1, int number2) const
{
    int leastCommonMultiple(0);

    if (number1 > number2)
    {
        leastCommonMultiple = number1;
    }
    else
    {
        leastCommonMultiple = number2;
    }

    while (true)
    {
        if (leastCommonMultiple % number1 == 0 && leastCommonMultiple % number2 == 0)
        {
            break;
        }
        leastCommonMultiple++;
    }

    return leastCommonMultiple;
}

int Rational::calculateGreatestCommonDivisor(int number1, int number2) const
{
    while (number2 != 0)
    {
        int gcd = number1 % number2;
        number1 = number2;
        number2 = gcd;
    }
    return number1;
}