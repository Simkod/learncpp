#pragma once

#ifndef BOOK_H
#define BOOK_H

#include "Date.h"

#include <string>
#include <vector>

//ISBN format e.g.: "978-3-16-148410-0"
class ISBN
{
public:
    ISBN();
    ISBN(std::string ISBNRaw);
    ~ISBN();

    bool isValid();

    char getSeparator() const;

    std::string getISBNasString() const;


private:
    std::string m_ISBN;

    char m_blockSeparator;

    std::vector<int> m_blockLengths;
};

class Book
{
public:

    enum Genre
    {
        Fiction = 0,
        NonFiction,
        Periodical,
        Biography,
        Children,
        Unknown = INT_MAX
    };

    Book(std::string rawISBN, std::string title, std::string author, Date copyrightDate, Genre genre);
    ~Book();

    bool operator<(const Book& book) const;
    bool operator==(const Book& book) const;
    bool operator!=(const Book& book) const;
    friend std::ostream& operator<<(std::ostream& os, const Book& book);

    ISBN getISBN() const;

    std::string getTitle() const;

    std::string getAuthor() const;

    Date getCopyrightDate() const;

    std::string getGenre() const;
    
private:
    bool isAuthorValid() const;
    bool checkBookValidity() const;

private:
    ISBN m_ISBN;
    std::string m_title;
    std::string m_author;
    Date m_copyrightDate;
    Genre m_genre;
};
#endif //BOOK_H