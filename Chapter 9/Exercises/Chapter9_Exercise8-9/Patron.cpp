
#include "Patron.h"

#include <assert.h>
#include <iostream>
#include "Library.h"

Patron::Patron(std::string name, int cardNumber, Library lib)
    : m_debt(0)
    , m_library(&lib)
{
    assert(name != "" && "No name given");
    m_name = name;

    assert(cardNumber != 0 && "No card number given");
    m_cardNumber = cardNumber;
}

Patron::~Patron()
{
}

std::string Patron::getName() const
{
    return m_name;
}

int Patron::getCardNumber() const
{
    return m_cardNumber;
}

int Patron::getDebt() const
{
    return m_debt;
}

void Patron::increaseDebt(int amount)
{
    assert(amount != 0 && "Cant increase something with 0");

    m_debt += amount;
}

void Patron::decreaseDebt(int amount)
{
    assert(amount != 0 && "Cant decrease something with 0");

    m_debt -= amount;
}

bool Patron::hasDebt() const
{
    if (m_debt == 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}


