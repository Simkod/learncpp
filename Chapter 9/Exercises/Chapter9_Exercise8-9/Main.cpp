//Chapter 9 Exercise 9

//Create a Library class.
//Include vectors of Books and Patrons.
//Include a struct called Transaction.
//Have it include a Book, a Patron, and a Date from the chapter.
//Make a vector of Transactions.
//Create functions to add books to the library, add patrons to the library, and check out books.
//Whenever a user checks out a book, have the library make sure that both the user and the book are in the library.
//If they aren�t, report an error.Then check to make sure that the user owes no fees.
//If the user does, report an error.
//If not, create a Transaction, and place it in the vector of Transactions.
//Also write a function that will return a vector that contains the names of all Patrons who owe fees.

#include "Library.h"
#include "Date.h"

void main()
{
    Library* niceLibrary = new Library();
    Date copyrightDate1 = Date(1992, mar, 26);
    Date copyrightDate2 = Date(1993, mar, 26);
    Date copyrightDate3 = Date(1994, mar, 26);
    Book ExampleBook1 = Book("978-3-16-148410-1", "Nice Title1", "Author Guy", copyrightDate1, Book::Genre::Children);
    Book ExampleBook2 = Book("978-3-16-148410-2", "Nice Title2", "Author Guy", copyrightDate2, Book::Genre::Fiction);
    Book ExampleBook3 = Book("978-3-16-148410-3", "Nice Title3", "Author Guy", copyrightDate3, Book::Genre::NonFiction);
    niceLibrary->addBook(ExampleBook1);
    niceLibrary->addBook(ExampleBook2);
    niceLibrary->addBook(ExampleBook3);
    niceLibrary->printBookData();
    niceLibrary->printUserData();
    niceLibrary->printAllTransactionData();

    LibraryActionHandler actionHandler(niceLibrary);
    std::vector<std::string> names{ "Harry", "James", "Conrad", "Franco" };
    actionHandler.createPersons(names);

    Person ourJames = actionHandler.getPersons()[1];

    actionHandler.personEntersLibrary(ourJames);
    actionHandler.personWantsToRentBookWithTitle(ourJames, "Nice Title2");

    niceLibrary->printBookData();
    niceLibrary->printUserData();
    niceLibrary->printAllTransactionData();

    system("pause");
}