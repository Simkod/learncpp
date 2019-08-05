#pragma once

#ifndef POPULATION_H
#define POPULATION_H

#include "Person.h"

#include <vector>



class Population
{
public:
    Population();
    ~Population();

    void addPerson(Person& personToAdd);

    std::vector<Person> getPopulation() const;

    void sortPopulationAlphabetically();

private:
    std::vector<Person> m_persons;
};



#endif