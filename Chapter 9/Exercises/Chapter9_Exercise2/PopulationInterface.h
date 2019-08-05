#pragma once

#ifndef POPULATIONINTERFACE_H
#define POPULATIONINTERFACE_H

#include "Person.h"

#include <vector>

class Population;

class PopulationInterface
{
public:
    PopulationInterface(Population* population);
    ~PopulationInterface();

    std::vector<Person> readInNamesAndAges();

    void addPersonToPopulation(Person personToAdd);

    void sortPopulationAlphabetically();

    void printPopulation() const;
    void printPopulationMember(int index) const;

    void generateArtificialPopulation(int sizeOfPopulation);  //For testing purposes

private: 



private:
    Population* m_population;
};



#endif