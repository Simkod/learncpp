#include "Library.h"
#include <assert.h>
#include <iostream>

//typedef std::pair<Book, bool> BookAndState;

Library::Library()
{
}

Library::~Library()
{
}

void Library::checkInBook(const Book& bookToCheckIn)
{
    auto book = m_BooksAndStates.find(bookToCheckIn);

    if (book->second == BookStatus::Out)
    {
        book->second = BookStatus::In;
    }
}

void Library::checkOutBook(const Book& bookToCheckOut)
{
    auto book = m_BooksAndStates.find(bookToCheckOut);

    if (book->second == BookStatus::In)
    {
        book->second = BookStatus::Out;
    }
}

std::map<Book, Library::BookStatus, Library::comp> Library::getBooksAndStates() const
{
    return m_BooksAndStates;
}

void Library::addBook(Book bookToAdd)
{
    int originalNumberOfBooks = m_BooksAndStates.size();

    std::pair<Book, BookStatus> bookAndState = std::make_pair(bookToAdd, BookStatus::In);
    m_BooksAndStates.insert(bookAndState);

    assert(originalNumberOfBooks + 1 == m_BooksAndStates.size() && "Book was not added");
}

void Library::printBookData() const
{

    std::cout << "Book# \t Author \t Title \t\t ISBN \t\t\t Copyright \t Status \t Genre";
    std::cout << "\n";

    int counter(1);
    for (std::map<Book, BookStatus, comp>::const_iterator it = m_BooksAndStates.begin(); it != m_BooksAndStates.end(); it++)
    {

        std::cout << counter << "  " << "\t"
                  << it->first.getAuthor() << "\t" 
                  << it->first.getTitle() << "\t" 
                  << it->first.getISBN().getISBNasString() << "\t"
                  << it->first.getCopyrightDate().getCopyrightDateAsString() << "\t"
                  << getBookStatus(it) << "\t\t"
                  << it->first.getGenre();
        std::cout << "\n";

        ++counter;
    }
    std::cout << "\n";
}

std::string Library::getBookStatus(std::map<Book, BookStatus, comp>::const_iterator it) const
{
    if (it->second == BookStatus::In)
    {
        return "In";
    }
    else if (it->second == BookStatus::Out)
    {
        return "Out";
    }
    else if (it->second == BookStatus::Unknown)
    {
        return "Unknown";
    }
    return "Problem";
}


