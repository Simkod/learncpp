#include "Transaction.h"

Transaction::Transaction(const Book* book, const Patron* patron, const Date date, Direction direction)
    : m_book(book)
    , m_patron(patron)
    , m_date(date)
    , m_direction(direction)
{

}

Transaction::~Transaction()
{
}

const Book* Transaction::getBook() const
{
    return m_book;
}

const Patron* Transaction::getPatron() const
{
    return m_patron;
}
 
const Date Transaction::getDate() const
{
    return m_date;
}

const Transaction::Direction Transaction::getDirection() const
{
    return m_direction;
}
