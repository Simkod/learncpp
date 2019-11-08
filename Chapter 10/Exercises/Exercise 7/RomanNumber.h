#pragma once

#ifndef ROMANNUMBER_H
#define ROMANNUMBER_H

#include <string>
#include <iostream>
#include <vector>

class RomanNumber
{
public:
    RomanNumber();
    RomanNumber(int value = 0);
    ~RomanNumber();

public:
    int getValue() const;
    std::string getValueInRomanRepresentation() const;

    RomanNumber operator+ (RomanNumber const &rhs);

private:
    std::vector<int> getDigits(int num) const;
    void initRomanRepresentation();

private:
    int m_value;
};

#endif //ROMANNUMBER_H