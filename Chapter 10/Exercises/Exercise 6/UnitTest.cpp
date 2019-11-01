#include "UnitTest.h"

UnitTest::UnitTest()
{
    m_testData.push_back(std::pair<int, std::string>(1, "I"));
    m_testData.push_back(std::pair<int, std::string>(11, "XI"));
    m_testData.push_back(std::pair<int, std::string>(222, "CCXXII"));
    m_testData.push_back(std::pair<int, std::string>(355, "CCCLV"));
    m_testData.push_back(std::pair<int, std::string>(789, "DCCLXXXIX"));
    m_testData.push_back(std::pair<int, std::string>(899, "DCCCXCIX"));
    m_testData.push_back(std::pair<int, std::string>(1501, "MDI"));
    m_testData.push_back(std::pair<int, std::string>(1744, "MDCCXLIV"));
    m_testData.push_back(std::pair<int, std::string>(2000, "MM"));
    m_testData.push_back(std::pair<int, std::string>(2812, "MMDCCCXII"));
    m_testData.push_back(std::pair<int, std::string>(3000, "MMM"));
    m_testData.push_back(std::pair<int, std::string>(3999, "MMMCMXCIX"));
}

UnitTest::~UnitTest()
{
}

bool UnitTest::runUnitTests()
{
    bool allUnitTestsOK = true;
    for (std::pair<int, std::string> data : m_testData)
    {
        allUnitTestsOK = test(data.first, data.second);
        if (!allUnitTestsOK)
        {
            std::cout << "One of the unit tests failed";
            return false;
        }
    }
    return true;
}

bool UnitTest::test(int& value, std::string& expectedResult)
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
