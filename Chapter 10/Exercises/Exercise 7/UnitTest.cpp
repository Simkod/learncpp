#include "UnitTest.h"

UnitTest::UnitTest()
{
    m_initTestData.push_back(std::pair<int, std::string>(0, "Number 0 has no Roman representation"));
    m_initTestData.push_back(std::pair<int, std::string>(1, "I"));
    m_initTestData.push_back(std::pair<int, std::string>(11, "XI"));
    m_initTestData.push_back(std::pair<int, std::string>(222, "CCXXII"));
    m_initTestData.push_back(std::pair<int, std::string>(355, "CCCLV"));
    m_initTestData.push_back(std::pair<int, std::string>(789, "DCCLXXXIX"));
    m_initTestData.push_back(std::pair<int, std::string>(899, "DCCCXCIX"));
    m_initTestData.push_back(std::pair<int, std::string>(1501, "MDI"));
    m_initTestData.push_back(std::pair<int, std::string>(1744, "MDCCXLIV"));
    m_initTestData.push_back(std::pair<int, std::string>(2000, "MM"));
    m_initTestData.push_back(std::pair<int, std::string>(2812, "MMDCCCXII"));
    m_initTestData.push_back(std::pair<int, std::string>(3000, "MMM"));
    m_initTestData.push_back(std::pair<int, std::string>(3999, "MMMCMXCIX"));

    m_additionTestData.push_back(std::pair<std::pair<int, int>, std::string>(std::pair<int, int>(0, 0), "Number 0 has no Roman representation"));
    m_additionTestData.push_back(std::pair<std::pair<int, int>, std::string>(std::pair<int, int>(1, 1), "II"));
    m_additionTestData.push_back(std::pair<std::pair<int, int>, std::string>(std::pair<int, int>(7, 2), "IX"));
    m_additionTestData.push_back(std::pair<std::pair<int, int>, std::string>(std::pair<int, int>(11, 44), "LV"));
    m_additionTestData.push_back(std::pair<std::pair<int, int>, std::string>(std::pair<int, int>(300, 211), "DXI"));
    m_additionTestData.push_back(std::pair<std::pair<int, int>, std::string>(std::pair<int, int>(555, 555), "MCX"));
    m_additionTestData.push_back(std::pair<std::pair<int, int>, std::string>(std::pair<int, int>(2001, 1998), "MMMCMXCIX"));

}

UnitTest::~UnitTest()
{
}

bool UnitTest::runUnitTests()
{
    bool unitTestOK = true;
    for (std::pair<int, std::string> data : m_initTestData)
    {
        unitTestOK = initTest(data.first, data.second);
        if (!unitTestOK)
        {
            std::cout << "One of the unit tests failed.";
            return false;
        }
    }

    for (std::pair<std::pair<int, int>, std::string> data : m_additionTestData)
    {
        unitTestOK = addTest(data.first.first, data.first.second, data.second);
        if (!unitTestOK)
        {
            std::cout << "One of the unit tests failed.";
            return false;
        }
    }

    return true;
}

bool UnitTest::initTest(int& value, std::string& expectedResult)
{
    RomanNumber newRoman(value);

    std::string valueInRoman = newRoman.getValueInRomanRepresentation();

    if (valueInRoman == expectedResult)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool UnitTest::addTest(int& value1, int& value2, std::string& expectedResult)
{
    RomanNumber roman1(value1);
    RomanNumber roman2(value2);

    int additionResult = value1 + value2;

    RomanNumber newRoman = roman2 + roman1;
    if (additionResult != newRoman.getValue())
    {
        return false;
    }

    std::string valueInRoman = newRoman.getValueInRomanRepresentation();

    if (valueInRoman == expectedResult)
    {
        return true;
    }
    else
    {
        return false;
    }
}
