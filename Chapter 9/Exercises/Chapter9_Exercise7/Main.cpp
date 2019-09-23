//Chapter 9 Exercise 7

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

    niceLibrary->checkOutBook(ExampleBook2);

    niceLibrary->printBookData();

    system("pause");
}
