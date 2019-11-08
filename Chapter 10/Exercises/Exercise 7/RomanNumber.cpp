#include "RomanNumber.h"

#include <map>
#include <vector>
#include <iostream>

static int s_maxValue = 3999;
static int s_minValue = 0;

static std::map<int, std::string> s_romanRepresentation;

RomanNumber::RomanNumber(int value)
{
    if (value > s_maxValue)
    {
        m_value = s_maxValue;
        std::cout << "Value maximum exceeded. Value set to maximum (" << s_maxValue << ").";
        std::cout << "\n";
    }
    else if (value < s_minValue)
    {
        m_value = 1;
        std::cout << "Value minimum exceeded. Value set to 1.";
        std::cout << "\n";
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

    if (valueInDigits[0] == 0 && valueInDigits.size() == 1 && romanValue == "")
    {
        romanValue = "Number 0 has no Roman representation";
    }

    return romanValue;
}

RomanNumber RomanNumber::operator+(RomanNumber const& rhs)
{
    int result = m_value + rhs.getValue();
    if (result > s_maxValue)
    {
        std::cout << "Value maximum exceeded after addition. The result of the addition can not be higher than " << s_maxValue << ".";
        std::cout << "\n";
        RomanNumber invalidRoman();
    }
    RomanNumber newRoman(result);

    return newRoman;
}

std::vector<int> RomanNumber::getDigits(int num) const
{
    std::vector<int> digits;
    int lastdigit = 0;
    if (num == 0)
    {
        digits.push_back(num);
    }
    else
    {
        while (num != 0)
        {
            lastdigit = num % 10;
            digits.insert(digits.begin(), lastdigit);
            num /= 10;
        }
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
