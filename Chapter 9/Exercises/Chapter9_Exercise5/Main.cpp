//Chapter 9 Exercise 5

//Design and implement a Book class, such as you can imagine as part of software for a library.
//Class Book should have members for the ISBN, title, author, and copyright date.
//Also store data on whether or not the book is checked out.
//Create functions for returning those data values.
//Create functions for checking a book in and out.
//Do simple validation of data entered into a Book, for example, accept ISBNs only of the form n - n - n - x where n is an integer and x is a digit or a letter.
//Store an ISBN as a string.

//TODOS
    //Nice To have: Separation: Model - Presenter - view 
        //Model: Book(has Date), Library(has BookFactory() ) 
        //Presenter: LibraryPresenter
        //View: LibraryView: Writing out messages and results, and asking for user input
            //Askuserwhattodo: Print books, Add book, Delete Book, 


#include "Library.h"
#include "Date.h"

void main()
{
    Library* niceLibrary = new Library();

    Date copyrightDate1 = Date(1992, mar, 26);
    Date copyrightDate2 = Date(1993, mar, 26);
    Date copyrightDate3 = Date(1994, mar, 26);
    Book ExampleBook1 = Book("978-3-16-148410-1", "Nice Title1", "Author Guy", copyrightDate1);
    Book ExampleBook2 = Book("978-3-16-148410-2", "Nice Title2", "Author Guy", copyrightDate2);
    Book ExampleBook3 = Book("978-3-16-148410-3", "Nice Title3", "Author Guy", copyrightDate3);

    niceLibrary->addBook(ExampleBook1);
    niceLibrary->addBook(ExampleBook2);
    niceLibrary->addBook(ExampleBook3);

    niceLibrary->printBookData();

    niceLibrary->checkOutBook(ExampleBook2);

    niceLibrary->printBookData();

    system("pause");
}
