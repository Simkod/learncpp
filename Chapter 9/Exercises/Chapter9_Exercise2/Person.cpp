#include "Person.h"

Person::Person(std::string name, double age)
    : m_name(name)
    , m_age(age)
{
}

Person::~Person()
{
}

std::string Person::getName() const
{
    return m_name;
}

double Person::getAge() const
{
    return m_age;
}

bool Person::operator<(const Person& person) const
{
    std:: string personName = person.getName();

    if (m_name != personName)
    {
        return personName < m_name;
    }
}

bool Person::operator>(const Person & person) const
{
    std::string personName = person.getName();

    if (m_name != personName)
    {
        return personName > m_name;
    }
}


