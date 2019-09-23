#pragma once

#ifndef LIBRARYACTIONHANDLER_H
#define LIBRARYACTIONHANDLER_H

#include "Library.h"
#include "Patron.h"

struct Person
{
    std::string name;
};

class LibraryActionHandler
{
public:
    LibraryActionHandler(Library* lib);
    ~LibraryActionHandler();

    void createPersons(std::vector<std::string> names);
    std::vector<Person> getPersons() const;

    void personEntersLibrary(Person& person);

    void personWantsToRentBookWithTitle(Person& person, std::string bookTitle);

    void printAllWithDebt()const;

private:
    Library* m_library;
    std::vector<Person> m_persons;
};

#endif //LIBRARYACTIONHANDLER_H
