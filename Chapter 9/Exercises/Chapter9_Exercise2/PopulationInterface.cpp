#include "PopulationInterface.h"
#include "Population.h"

#include <iostream>

PopulationInterface::PopulationInterface(Population* population)
    : m_population(population)
{
}

PopulationInterface::~PopulationInterface()
{
}

std::vector<Person> PopulationInterface::readInNamesAndAges()
{
    std::vector<Person> newPersons;

    bool newEntry(true);
    while (newEntry)
    {
        std::cout << "Name: ";
        std::string name("");
        std::cin >> name;
        std::cout << "\n";

        std::cout << "Age: ";
        double age(0);
        std::cin >> age;
        std::cout << "\n";

        Person newPerson = Person(name, age);
        newPersons.push_back(newPerson);

        bool userAnsweredCorrectly(false);
        while (!userAnsweredCorrectly)
        {
            std::cout << "New Entry? (Y/N) :";
            char answer = char();
            std::cin >> answer;
            std::cout << "\n";

            if (answer == 'y' || answer == 'Y')
            {
                newEntry = true;
                userAnsweredCorrectly = true;
            }
            else if (answer == 'n' || answer == 'N')
            {
                newEntry = false;
                userAnsweredCorrectly = true;
            }
            else
            {
                std::cout << "Wrong answer, try again!";
                std::cout << "\n";
                userAnsweredCorrectly = false;
            }
        }
    
    }
    return newPersons;
}

void PopulationInterface::addPersonToPopulation(Person personToAdd)
{
    m_population->addPerson(personToAdd);
}

void PopulationInterface::sortPopulationAlphabetically()
{
    m_population->sortPopulationAlphabetically();
}

void PopulationInterface::printPopulation() const
{
    std::cout << "Population:" << "\n\n";
    
    std::vector<Person> populationToPrint = m_population->getPopulation();

    std::cout << "Size: " << populationToPrint.size() << "\n\n";

    std::cout << "Name" << "\t" << "Age" << "\n";

    for (std::vector<Person>::const_iterator personIt = populationToPrint.begin(); personIt != populationToPrint.end(); ++personIt)
    {
        std::cout << personIt->getName() << "\t" << personIt->getAge();
        std::cout << "\n";
    }
    std::cout << "\n";
}

void PopulationInterface::printPopulationMember(int index) const
{
    std::cout << index << "-th member of Population:" << "\n\n";

    std::vector<Person> population = m_population->getPopulation();

    std::cout << "Name" << "\t" << "Age" << "\n";

    const int correctedIndex = index - 1;  //Population indexes starts with 0, because it is a vector
    std::cout << population[correctedIndex].getName() << "\t" << population[correctedIndex].getAge();
    std::cout << "\n";
    std::cout << "\n";

}

void PopulationInterface::generateArtificialPopulation(int sizeOfPopulation)
{

    if (m_population->getPopulation().empty())
    {
        char c('o');
        double age(0);

        for (int i = 0; i < sizeOfPopulation; ++i)
        {
            std::string name(1, c);
            Person newPerson = Person(name, age);

            addPersonToPopulation(newPerson);

            --c;
            ++age;
        }
    }
    else
    {
        std::cout << "Generating Artificial Population failed, because a population already exists.";
        std::cout << "\n";
    }
   
}

