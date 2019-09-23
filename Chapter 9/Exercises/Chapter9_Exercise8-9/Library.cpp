#include "Library.h"
#include <assert.h>
#include <iostream>

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

std::map<Book, Library::BookStatus, Library::compBook> Library::getBooksAndStates() const
{
    return m_BooksAndStates;
}

std::map<Patron, Library::UserStatus, Library::compPatron> Library::getUsersAndStates() const
{
    return m_usersAndStates;
}

void Library::addBook(Book bookToAdd)
{
    int originalNumberOfBooks = m_BooksAndStates.size();

    std::pair<Book, BookStatus> bookAndState = std::make_pair(bookToAdd, BookStatus::In);
    m_BooksAndStates.insert(bookAndState);

    assert(originalNumberOfBooks + 1 == m_BooksAndStates.size() && "Book was not added");
}

void Library::addNewUser(std::string name)
{
    Patron newUser(name, generateNextCardNumber(), *this);

    std::pair<Patron, UserStatus> userAndState = std::make_pair(newUser, UserStatus::Inside);

    m_usersAndStates.insert(userAndState);
}

void Library::printBookData() const
{
    std::cout << "Book# \t Author \t Title \t\t ISBN \t\t\t Copyright \t Status \t Genre";
    std::cout << "\n";

    int counter(1);
    for (std::map<Book, BookStatus, compBook>::const_iterator it = m_BooksAndStates.begin(); it != m_BooksAndStates.end(); it++)
    {

        std::cout << counter << "  " << "\t"
                  << it->first.getAuthor() << "\t" 
                  << it->first.getTitle() << "\t" 
                  << it->first.getISBN().getISBNasString() << "\t"
                  << it->first.getCopyrightDate().getDateAsString() << "\t"
                  << getBookStatus(it) << "\t\t"
                  << it->first.getGenre();
        std::cout << "\n";

        ++counter;
    }
    std::cout << "\n";
}

void Library::printUserData() const
{
    std::cout << "User# \t Name \t CardNumber \t DebtAmount \n";

    int counter(1);
    for (std::map<Patron, UserStatus, compBook>::const_iterator it = m_usersAndStates.begin(); it != m_usersAndStates.end(); it++)
    {
        std::cout << counter << "  " << "\t"
            << it->first.getName() << "\t\t"
            << it->first.getCardNumber() << "\t\t"
            << it->first.getDebt() << "\t";

        //std::cout << "Rented Books: \n";
        //std::cout << "Book# \t Author \t Title \t\t ISBN \t\t\t Copyright";
        //std::cout << "\n";
        //std::vector<const Book*> rentedBooks = it->first.getRentedBooks();
        //for (int i = 0 ; i < rentedBooks.size(); ++i)
        //{
        //    std::cout << rentedBooks[i]->getAuthor() << "\t"
        //        << rentedBooks[i]->getTitle() << "\t"
        //        << rentedBooks[i]->getISBN().getISBNasString() << "\t"
        //        << rentedBooks[i]->getCopyrightDate().getCopyrightDateAsString();
        //    std::cout << "\n";
        //}
        std::cout << "\n";
        ++counter;
    }

    std::cout << "\n";
}

void Library::printAllTransactionData() const
{
    std::cout << "Book Title \t UserName \t Date \t Direction\n";

    for (std::vector<Transaction>::const_iterator it = m_transactions.begin(); it != m_transactions.end(); it++)
    {
        std::cout << it->getBook()->getTitle() << "\t";
        std::cout << it->getPatron()->getName() << "\t\t";
        std::cout << it->getDate().getDateAsString() << "\t";
        std::cout << it->getDirection() << "\t";
        std::cout << "\n";
    }

    std::cout << "\n";
}

void Library::printAllUserWithDebt() const
{
    std::cout << "UserName \t Debt\n";

    std::vector<const Patron*> usersWithDebt = getAllUsersWithDebt();
    if (!usersWithDebt.empty())
    {
        for (int i = 0; i < usersWithDebt.size(); i++)
        {
            std::cout<< usersWithDebt[i]->getName() << "\t";
            std::cout << usersWithDebt[i]->getDebt() << "\t";
            std::cout << "\n";
        }
        std::cout << "\n";
    }
}

void Library::someoneWantsToRentaBookbyTitle(std::string name, std::string bookTitle)
{
    if (!isUserInDatabase(name))
    {
        std::cout << "Not a Library member.";
    }
    else
    {
        std::map<Patron, Library::UserStatus, Library::compPatron>::iterator user = searchUser(name);

        if (isBookInDatabase(bookTitle))
        {
            std::map<Book, Library::BookStatus, Library::compBook>::iterator book = searchBook(bookTitle);
            
            if (isBookRentable(book->first))
            {
                
                if (isUserAllowedToRent(user->first))
                {
                    //Check Out book 
                    checkOutBook(book->first);
                    //Add transaction
                    const Book* bookPtr;
                    bookPtr = &book->first;
                    const Patron* patronPtr;
                    patronPtr = &user->first;

                    Date today = Date(2019, sep, 23); //Hardcoded...

                    createTransaction(bookPtr, patronPtr, today, Transaction::Direction::Out);
                }
                else
                {
                    std::cout << "User is not allowed to rent.";
                }
            }
            else
            {
                std::cout << "Book is Out.";
            }
        }
        else
        {
            std::cout << "No Book with the given Title in the database.";
        }
    }
}

void Library::userLateWithBook(std::string name)
{
    std::map<Patron, Library::UserStatus, Library::compPatron>::iterator user = searchUser(name);
    /*user->first.increaseDebt(10);*/

}

bool Library::isBookRentable(Book book)
{
    auto itr = m_BooksAndStates.find(book);

    if (itr->second == In)
    {
        return true;
    }
    else
    {
        return false;
    }
}

std::map<Patron, Library::UserStatus, Library::compPatron>::iterator Library::searchUser(std::string userName)
{
    for (std::map<Patron, UserStatus, compPatron>::iterator it = m_usersAndStates.begin(); it != m_usersAndStates.end(); ++it)
    {
        if (it->first.getName() == userName)
        {
            return it;
        }
    }
    return m_usersAndStates.end();
}

std::map<Book, Library::BookStatus, Library::compBook>::iterator Library::searchBook(std::string title)
{
    for (std::map<Book, BookStatus, compBook>::iterator it = m_BooksAndStates.begin(); it != m_BooksAndStates.end(); ++it)
    {
        if (it->first.getTitle() == title)
        {
            return it;
        }
    }
    return m_BooksAndStates.end();
}

bool Library::isBookInDatabase(std::string title)
{
    std::map<Book, BookStatus, compBook>::iterator book = searchBook(title);
    if (book == m_BooksAndStates.end())
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool Library::isUserInDatabase(std::string name)
{
    std::map<Patron, UserStatus, compPatron>::iterator user = searchUser(name);
    if (user == m_usersAndStates.end())
    {
        return false;
    }
    else
    {
        return true;
    }
}

void Library::createTransaction(const Book* book, const Patron* patron, Date date, Transaction::Direction dir)
{
    Transaction newTransaction(book, patron, date, dir);
    m_transactions.push_back(newTransaction);
}

std::vector<const Patron*> Library::getAllUsersWithDebt() const
{
    std::vector<const Patron*> usersWithDebt;

    for(std::map<Patron, UserStatus, compPatron>::const_iterator it = m_usersAndStates.begin(); it != m_usersAndStates.end(); ++it)
    {
        if (it->first.hasDebt())
        {
            const Patron* user;
            user = &it->first;
            usersWithDebt.push_back(user);
        }
    }
    return usersWithDebt;
}


void Library::setUserStatus(std::map<Patron, UserStatus, compPatron>::iterator it, UserStatus status)
{
    it->second = status;
}

void Library::someoneEnteredTheLibrary(std::string name)
{
    std::map<Patron, UserStatus, compPatron>::iterator user = searchUser(name);
    if (user == m_usersAndStates.end())
    //{
        addNewUser(name);
    }
    else
    {
        setUserStatus(user, Inside);
    }
}

std::string Library::getBookStatus(std::map<Book, BookStatus, compBook>::const_iterator it) const
{
    if (it->second == BookStatus::In)
    {
        return "In";
    }
    else if (it->second == BookStatus::Out)
    {
        return "Out";
    }
    return "Problem";
}

int Library::generateNextCardNumber() const
{
    if (m_usersAndStates.empty())
    {
        return 100;
    }
    else
    {
        return m_usersAndStates.end()->first.getCardNumber();
    }
}

bool Library::isUserAllowedToRent(Patron user)
{
    if (!user.hasDebt())
    {
        return true;
    }
    return false;
}

