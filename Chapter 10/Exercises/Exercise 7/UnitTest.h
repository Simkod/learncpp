#pragma once

#ifndef UNITTEST_H
#define UNITTEST_H

#include "RomanNumber.h"

class UnitTest
{
public:
    UnitTest();
    ~UnitTest();

    bool runUnitTests();

private:
    bool initTest(int& value, std::string& expectedResult);
    bool addTest(int& value1, int& value2, std::string& expectedResult);

private:
    std::vector<std::pair<int, std::string> > m_initTestData;
    std::vector<std::pair<std::pair<int, int>, std::string> > m_additionTestData;
};

#endif //UNITTEST_H
