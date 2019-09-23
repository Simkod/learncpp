#include "LibraryActionHandler.h"

LibraryActionHandler::LibraryActionHandler(Library* lib)
    : m_library(lib)
{
}

LibraryActionHandler::~LibraryActionHandler()
{
}

std::vector<Person> LibraryActionHandler::getPersons() const
{
    return m_persons;
}

void LibraryActionHandler::createPersons(std::vector<std::string> names)
{
    for (int i = 0; i < names.size(); ++i)
    {
        Person newPerson;
        newPerson.name = names[i];
        m_persons.push_back(newPerson);
    }
}

void LibraryActionHandler::personEntersLibrary(Person& person)
{
    m_library->someoneEnteredTheLibrary(person.name);
}

void LibraryActionHandler::personWantsToRentBookWithTitle(Person& person, std::string bookTitle)
{
    m_library->someoneWantsToRentaBookbyTitle(person.name, bookTitle);
}

void LibraryActionHandler::printAllWithDebt() const
{
    m_library->printAllUserWithDebt;
}


