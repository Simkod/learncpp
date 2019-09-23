#pragma once

#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "Book.h"
#include "Patron.h"

class Transaction
{
public:

    enum Direction
    {
        In = 1,
        Out = 2
    };

    Transaction(const Book* book, const Patron* patron, const Date date, Direction direction);
    ~Transaction();

    const Book* getBook() const;
    const Patron* getPatron() const;
    const Date getDate()const;
    const Direction getDirection() const;

private:
    const Book* m_book;
    const Patron* m_patron;
    const Date m_date;
    const Direction m_direction;
};

#endif //TRANSACTION_H