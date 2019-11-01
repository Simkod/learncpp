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
    bool test(int& value, std::string& expectedResult);

private:
    std::vector<std::pair<int, std::string> > m_testData;
};

#endif //UNITTEST_H
