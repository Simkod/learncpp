#pragma once

#ifndef LIBRARY_H
#define LIBRARY_H

#include "Book.h"
#include "Patron.h"

#include <map>
#include "LibraryActionHandler.h"
#include "Transaction.h"

class Library
{
public:
    Library();
    ~Library();

    enum BookStatus
    {
        Out = 0,
        In = 1
    };

    enum UserStatus
    {
        Outside = 0,
        Inside = 1
    };

    struct compBook
    {
        bool operator()(const Book &lhs, const Book &rhs) const
        {
                return lhs.getTitle() < rhs.getTitle();
        }
    };

    struct compPatron
    {
        bool operator()(const Patron &lhs, const Patron &rhs) const
        {
            return lhs.getName() < rhs.getName();
        }
    };

    std::map<Book, Library::BookStatus, compBook> getBooksAndStates() const;
    std::map<Patron, UserStatus, compPatron> getUsersAndStates() const;

    void addBook(Book bookToAdd);

    void addNewUser(std::string name);

    void printBookData() const;

    void printUserData() const;

    void printAllTransactionData() const;

    void printAllUserWithDebt() const;

    void someoneEnteredTheLibrary(std::string name);

    void someoneWantsToRentaBookbyTitle(std::string name, std::string bookTitle);

    void userLateWithBook(std::string name);

private:
    std::string getBookStatus(std::map<Book, BookStatus, compBook>::const_iterator it) const;

    void checkInBook(const Book& bookToCheckIn);

    void checkOutBook(const Book& bookToCheckOut);

    int generateNextCardNumber() const;

    bool isUserAllowedToRent(Patron user);

    bool isBookRentable(Book book);

    void setUserStatus(std::map<Patron, UserStatus, compPatron>::iterator it, UserStatus status);

    std::map<Patron, UserStatus, compPatron>::iterator searchUser(std::string userName);

    std::map<Book, BookStatus, compBook>::iterator searchBook(std::string title);

    bool isBookInDatabase(std::string title);

    bool isUserInDatabase(std::string name);

    void createTransaction(const Book* book, const Patron* patron, Date m_date, Transaction::Direction dir);

    std::vector<const Patron*> getAllUsersWithDebt() const;

private:
    std::map<Book, BookStatus, compBook> m_BooksAndStates;

    std::map<Patron, UserStatus, compPatron> m_usersAndStates;

    std::vector<Transaction> m_transactions;
};

#endif //LIBRARY_H