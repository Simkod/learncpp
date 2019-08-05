#pragma once

#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person
{
public:
    Person(std::string name, double age);
    ~Person();

    std::string getName() const;
    double getAge() const;

    bool operator<(const Person& person) const;
    bool operator>(const Person& person) const;

private:
    std::string m_name;
    double m_age;
};

#endif //PERSON_H