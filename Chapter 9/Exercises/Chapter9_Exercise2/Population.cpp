#include "Population.h"

#include <algorithm>

Population::Population()
{
}

Population::~Population()
{
}

void Population::addPerson(Person& personToAdd)
{
    m_persons.push_back(personToAdd);
}

std::vector<Person> Population::getPopulation() const
{
    return m_persons;
}

void Population::sortPopulationAlphabetically()
{
    std::sort(m_persons.begin(), m_persons.end(), std::greater<Person>());
}
