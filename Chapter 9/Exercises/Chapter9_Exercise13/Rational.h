#pragma once

#ifndef RATIONAL_H
#define RATIONAL_H

// Rational number is a number that can be expressed as:
// the quotient or fraction p / q of two integers, a numerator p and a non-zero denominator q.
// Since q may be equal to 1, every integer is a rational number.

class Rational
{
public:
    Rational(int numerator, int denominator);
    ~Rational();

    Rational operator*(Rational& rhs);
    Rational operator/(Rational& rhs);
    Rational operator+(Rational& rhs);
    Rational operator-(Rational& rhs);
    bool operator==(Rational& rhs);

public:
    int getNumerator() const;

    int getDenominator() const;

    double getRationalAsDouble() const;

private:
    void simplify();
    void setDenominator(int denominator);
    void setNumerator(int numerator);
    int calculateLeastCommonMultiple(int number1, int number2) const;
    int calculateGreatestCommonDivisor(int number1, int number2) const;

private:
    int m_numerator;
    int m_denominator;
};

#endif // RATIONAL_H
