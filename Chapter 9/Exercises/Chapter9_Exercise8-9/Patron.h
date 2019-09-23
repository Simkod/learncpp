#pragma once

#ifndef PATRON_H
#define PATRON_H

#include "Book.h"

#include <string>
#include <vector>

class Library;

class Patron
{
public:
    Patron(std::string name, int cardNumber, Library lib);
    ~Patron();

    std::string getName() const;

    int getCardNumber() const;

    int getDebt() const;
    void increaseDebt(int amount);
    void decreaseDebt(int amount);

    bool hasDebt() const;

private:
    std::string m_name;
    int m_cardNumber;
    int m_debt;
    Library* m_library;
};

#endif //LIBRARY_H