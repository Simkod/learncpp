#pragma once

#ifndef LIBRARY_H
#define LIBRARY_H

#include "Book.h"

#include <map>

class Library
{
public:
    Library();
    ~Library();

    enum BookStatus
    {
        Out = 0,
        In = 1,
        Unknown = INT_MAX
    };

    struct comp
    {
        bool operator()(const Book &lhs, const Book &rhs) const
        {
                return lhs.getTitle() < rhs.getTitle();
        }
    };

    void checkInBook(const Book& bookToCheckIn);
    void checkOutBook(const Book& bookToCheckOut);

    std::map<Book, Library::BookStatus, comp> getBooksAndStates() const;
    
    void addBook(Book bookToAdd);

    void printBookData() const;

private:
    std::string getBookStatus(std::map<Book, BookStatus, comp>::const_iterator it) const;

private:
    std::map<Book, BookStatus, comp> m_BooksAndStates;
};

#endif //LIBRARY_H