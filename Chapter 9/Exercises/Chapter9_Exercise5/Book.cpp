#include "Book.h" 
#include "Date.h"

#include <algorithm>
#include <iostream>

Book::Book(std::string rawISBN, std::string title, std::string author, Date copyrightDate)
    : m_title(title)
    , m_author(author)
    , m_copyrightDate(copyrightDate)
{
    m_ISBN = ISBN(rawISBN);

    bool bookValid = checkBookValidity();
    if (!bookValid)
    {
        std::cout << "Book is not Valid. \n";
    }
}

Book::~Book()
{
}

ISBN::ISBN()
{
}

ISBN::ISBN(std::string ISBNRaw)
{
    //e.g. "978-3-16-148410-0"
    m_blockLengths = { 3,1,2,6,1 };
    m_blockSeparator = '-';
    m_ISBN = ISBNRaw;
}

ISBN::~ISBN()
{
}

bool ISBN::isValid()
{
    std::string currentlyCheckedBlock;

    int blockCounter(0);
    for (char& ch : m_ISBN)
    {
        if (ch != m_blockSeparator)
        {
            if (blockCounter < m_blockLengths.size())
            {
                if (!isdigit(ch))
                {
                    std::cout << "Incorrect ISBN. It should be in the format: ###-#-##-######-C , where C can be a digit or a letter";
                    return false;
                }
                currentlyCheckedBlock += ch;
            }
            else
            {
                currentlyCheckedBlock += ch;
            }

            if (currentlyCheckedBlock.size() > m_blockLengths[blockCounter])
            {
                std::cout << "Incorrect ISBN. Block" << blockCounter << "is too long. The format should be: ###-#-##-######-C , where C can be a digit or a letter";
                return false;
            }
        }
        else
        {
            if (currentlyCheckedBlock.size() != m_blockLengths[blockCounter])
            {
                std::cout << "Incorrect ISBN. Block" << blockCounter << "is not matching. The format should be: ###-#-##-######-C , where C can be a digit or a letter";
                return false;
            }
            currentlyCheckedBlock.clear();
            ++blockCounter;
        }
    }
    return true;
}

char ISBN::getSeparator() const
{
    return m_blockSeparator;
}

std::string ISBN::getISBNasString() const
{
    return m_ISBN;
}

bool Book::operator<(const Book& otherBook) const
{
    return m_author < otherBook.getAuthor();
}

ISBN Book::getISBN() const
{
    return m_ISBN;
}

std::string Book::getTitle() const
{
    return m_title;
}

std::string Book::getAuthor() const
{
    return m_author;
}

Date Book::getCopyrightDate() const
{
    return m_copyrightDate;
}

bool Book::isAuthorValid() const
{
    if (std::any_of(m_author.begin(), m_author.end(), ::isdigit))
    {
        std::cout << "Incorrect Author. Author's name should only contain letters. \n";
        return false;
    }
    return true;
}

bool Book::checkBookValidity() 
{
    if (!getISBN().isValid() || !isAuthorValid())
    {
        return false;
    }
    return true;
}
