#include "RomanNumber.h"

#include <map>
#include <vector>
#include <iostream>

static int s_maxValue = 4000;
static int s_minValue = 1;

static std::map<int, std::string> s_romanRepresentation;

RomanNumber::RomanNumber(int value)
{
    if (value > s_maxValue)
    {
        m_value = s_maxValue;
        std::cout << "Value maximum exceeded. Value set to maximum (" << s_maxValue << ").";
    }
    else if (value < s_minValue)
    {
        m_value = s_minValue;
        std::cout << "Value minimum exceeded. Value set to minimum (" << s_minValue << ").";
    }
    else
    {
        m_value = value;
    }

    if (s_romanRepresentation.empty())
    {
        initRomanRepresentation();
    }
}

RomanNumber::~RomanNumber()
{

}

int RomanNumber::getValue() const
{
    return m_value;
}

std::string RomanNumber::getValueInRomanRepresentation() const
{
    std::string romanValue = "";

    std::vector<int> valueInDigits = getDigits(m_value);
    std::reverse(valueInDigits.begin(), valueInDigits.end());

    for (int index = 0; index != valueInDigits.size(); ++index)
    {
        int numberToTranslate = valueInDigits[index] * pow(10, index);
        std::map<int, std::string>::iterator it = s_romanRepresentation.find(numberToTranslate);
        romanValue.insert(0, it->second);
    }

    return romanValue;
}

std::vector<int> RomanNumber::getDigits(int num) const
{
    std::vector<int> digits;
    int lastdigit = 0;
    while (num != 0)
    {
        lastdigit = num % 10;
        digits.insert(digits.begin(), lastdigit);
        num /= 10;
    }
    return digits;
}

void RomanNumber::initRomanRepresentation()
{
    s_romanRepresentation.insert(std::pair<int, std::string>(0, ""));

    s_romanRepresentation.insert(std::pair<int, std::string>(1, "I"));
    s_romanRepresentation.insert(std::pair<int, std::string>(2, "II"));
    s_romanRepresentation.insert(std::pair<int, std::string>(3, "III"));
    s_romanRepresentation.insert(std::pair<int, std::string>(4, "IV"));
    s_romanRepresentation.insert(std::pair<int, std::string>(5, "V"));
    s_romanRepresentation.insert(std::pair<int, std::string>(6, "VI"));
    s_romanRepresentation.insert(std::pair<int, std::string>(7, "VII"));
    s_romanRepresentation.insert(std::pair<int, std::string>(8, "VIII"));
    s_romanRepresentation.insert(std::pair<int, std::string>(9, "IX"));
    s_romanRepresentation.insert(std::pair<int, std::string>(10, "X"));

    s_romanRepresentation.insert(std::pair<int, std::string>(20, "XX"));
    s_romanRepresentation.insert(std::pair<int, std::string>(30, "XXX"));
    s_romanRepresentation.insert(std::pair<int, std::string>(40, "XL"));
    s_romanRepresentation.insert(std::pair<int, std::string>(50, "L"));
    s_romanRepresentation.insert(std::pair<int, std::string>(60, "LX"));
    s_romanRepresentation.insert(std::pair<int, std::string>(70, "LXX"));
    s_romanRepresentation.insert(std::pair<int, std::string>(80, "LXXX"));
    s_romanRepresentation.insert(std::pair<int, std::string>(90, "XC"));
    s_romanRepresentation.insert(std::pair<int, std::string>(100, "C"));

    s_romanRepresentation.insert(std::pair<int, std::string>(200, "CC"));
    s_romanRepresentation.insert(std::pair<int, std::string>(300, "CCC"));
    s_romanRepresentation.insert(std::pair<int, std::string>(400, "CD"));
    s_romanRepresentation.insert(std::pair<int, std::string>(500, "D"));
    s_romanRepresentation.insert(std::pair<int, std::string>(600, "DC"));
    s_romanRepresentation.insert(std::pair<int, std::string>(700, "DCC"));
    s_romanRepresentation.insert(std::pair<int, std::string>(800, "DCCC"));
    s_romanRepresentation.insert(std::pair<int, std::string>(900, "CM"));
    s_romanRepresentation.insert(std::pair<int, std::string>(1000, "M"));

    s_romanRepresentation.insert(std::pair<int, std::string>(2000, "MM"));
    s_romanRepresentation.insert(std::pair<int, std::string>(3000, "MMM"));
}
