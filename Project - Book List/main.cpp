#include <iostream>
#include <string>
#include "Book.hpp"
#include "Library.hpp"
using namespace std;


void TestLibraryMemAllocation( Library &library )
{
    int memberNum = 8;

    library.AllocateMemory( memberNum );

    if ( library.GetArraySize() != memberNum )
    {
        cout << "LIBRARY ALLOCATE MEMORY TEST FAILED" << endl;
        cout << "Expected Size: " << memberNum << endl;
        cout << "Received Size: " << library.GetArraySize() << endl << endl;
    }
    else
    {
        cout << "LIBRARY ALLOCATE MEMORY TEST PASSED" << endl << endl;
    }

}

void TestLibraryResizeArray( Library &library)
{
    int expectedSize = library.GetArraySize() + 10;
    library.ResizeArray();

    if ( library.GetArraySize() != expectedSize )
    {
        cout << "LIBRARY RESIZE ARRAY TEST FAILED" << endl;
        cout << "Expected Size: " << expectedSize << endl;
        cout << "Received Size: " << library.GetArraySize() << endl << endl;
    }
    else
    {
        cout << "LIBRARY RESIZE ARRAY TEST PASSED" << endl << endl;
    }
}

void TestLibraryViewBooks( Library &library )
{
    for (int i = 0; i < 3; i++)
    {
        library.NewBook();
    }
    library.ViewAllBooks();
}

void TestLibraryUserResize(Library &library)
{
    for (int i = 0; i < 4; i++)
    {
        TestLibraryViewBooks( library );
    }
}

void TestLibraryUpdateBook( Library &library )
{
    library.UpdateBook();
    library.ViewAllBooks();
}

void TestLibraryClass()
{
    cout << endl << endl;
    Library library;
    TestLibraryMemAllocation( library );
    TestLibraryResizeArray( library );


    library.~Library();
    TestLibraryViewBooks( library );

    TestLibraryUserResize( library );

    library.~Library();
    TestLibraryUpdateBook( library );
}

void TestBookInfo( Book &book, string &title, string &author )
{
    book.SetBookInfo( title, author );

    if ( book.GetTitle() != title || book.GetAuthor() != author )
    {
        cout << "BOOK INFO TEST FAILED" << endl;
        if ( book.GetTitle() != title )
        {
            cout << "Expected Title: " << title << endl << "Received: \t" << book.GetTitle() << endl << endl;
        }

        if ( book.GetAuthor() != author )
        {
            cout << "Expected Author:" << title << endl << "Received: " << book.GetTitle() << endl << endl;
        }
    }
    else
    {
        cout << "BOOK INFO TEST PASSED" << endl << endl;
    }

}
void TestPurchaseStatus( Book &book)
{
    PurchaseStatus psOwned = OWNED;
    PurchaseStatus psWishlist = WISHLIST;
    book.SetPurchaseStatus( psOwned );

    if ( book.GetPurchaseStatus() != psOwned )
    {
        cout << "BOOK PURCHASE STATUS TEST 1.1 FAILED" << endl;
        cout << "Expected: " << psOwned << endl;
        cout << "Received: " << book.GetPurchaseStatus() << endl << endl;
    }
    else
    {
        cout << "BOOK PURCHASE STATUS TEST 1.1 PASSED" << endl << endl;
    }

    if ( book.GetPurchaseStatusString() != "Owned" )
    {
        cout << "BOOK PURCHASE STATUS TEST 1.2 FAILED" << endl;
        cout << "Expected: Owned" << endl;
        cout << "Received: " << book.GetPurchaseStatusString() << endl << endl;
    }
    else
    {
        cout << "BOOK PURCHASE STATUS TEST 1.2 PASSED" << endl << endl;
    }
    book.SetPurchaseStatus( psWishlist );

    if ( book.GetPurchaseStatus() != psWishlist )
    {
        cout << "BOOK PURCHASE STATUS TEST 2.1 FAILED" << endl;
        cout << "Expected: " << psWishlist << endl;
        cout << "Received: " << book.GetPurchaseStatus() << endl << endl;
    }
    else
    {
        cout << "BOOK PURCHASE STATUS TEST 2.1 PASSED" << endl << endl;
    }

    if ( book.GetPurchaseStatusString() != "Wishlist" )
    {
        cout << "BOOK PURCHASE STATUS TEST 2.2 FAILED" << endl;
        cout << "Expected: Wishlist" << endl;
        cout << "Received: " << book.GetPurchaseStatusString() << endl << endl;
    }
    else
    {
        cout << "BOOK PURCHASE STATUS TEST 2.2 PASSED" << endl << endl;
    }
}

void TestReadingStatus( Book &book )
{
    ReadingStatus rsNotStarted = NOT_STARTED;
    ReadingStatus rsReading = READING;
    ReadingStatus rsFinished = FINISHED;

    book.SetReadingStatus( rsNotStarted);

    ///Verify Status as "Not started"
    if ( book.GetReadingStatus() != rsNotStarted )
    {
        cout << "BOOK READING STATUS TEST 1.1 FAILED" << endl;
        cout << "Expected: " << rsNotStarted << endl;
        cout << "Received: " << book.GetReadingStatus() << endl << endl;
    }
    else
    {
        cout << "BOOK READING STATUS TEST 1.1 PASSED" << endl << endl;
    }

    if ( book.GetReadingStatusString() != "Not started" )
    {
        cout << "BOOK READING STATUS TEST 1.2 FAILED" << endl;
        cout << "Expected: Not started" << endl;
        cout << "Received: " << book.GetReadingStatusString() << endl << endl;
    }
    else
    {
        cout << "BOOK READING STATUS TEST 1.2 PASSED" << endl << endl;
    }

    ///Verify status as "Reading"
    book.SetReadingStatus( rsReading );
    if ( book.GetReadingStatus() != rsReading )
    {
        cout << "BOOK READING STATUS TEST 2.1 FAILED" << endl;
        cout << "Expected: " << rsReading << endl;
        cout << "Received: " << book.GetReadingStatus() << endl << endl;
    }
    else
    {
        cout << "BOOK READING STATUS TEST 2.1 PASSED" << endl << endl;
    }

    if ( book.GetReadingStatusString() != "Reading" )
    {
        cout << "BOOK READING STATUS TEST 2.2 FAILED" << endl << endl;
        cout << "Expected: Reading" << endl;
        cout << "Received: " << book.GetReadingStatusString() << endl << endl;
    }
    else
    {
        cout << "BOOK READING STATUS TEST 2.2 PASSED" << endl << endl;
    }

    ///Verify status as "Finished"
    book.SetReadingStatus( rsFinished );
    if ( book.GetReadingStatus() != rsFinished )
    {
        cout << "BOOK READING STATUS TEST 3.1 FAILED" << endl;
        cout << "Expected: " << rsFinished << endl;
        cout << "Received: " << book.GetReadingStatus() << endl << endl;
    }
    else
    {
        cout << "BOOK READING STATUS TEST 3.1 PASSED" << endl << endl;
    }

    if ( book.GetReadingStatusString() != "Finished" )
    {
        cout << "BOOK READING STATUS TEST 3.2 FAILED" << endl;
        cout << "Expected: Finished" << endl;
        cout << "Received: " << book.GetReadingStatusString() << endl << endl;
    }
    else
    {
        cout << "BOOK READING STATUS TEST 3.2 PASSED" << endl << endl;
    }

}
void TestDisplayBook( Book &book)
{
    ReadingStatus rs = FINISHED;
    PurchaseStatus ps = WISHLIST;

    book.SetReadingStatus( rs );
    book.SetPurchaseStatus( ps );
    cout << "Test of Book Display:" << endl;
    book.DisplayBook();

}

void TestBookClass()
{
    Book book;
    string title = "There and Back Again: A Hobbit's Holiday";
    string author = "Bilbo Baggins";

    TestBookInfo( book, title, author );
    TestPurchaseStatus( book );
    TestReadingStatus( book );
    TestDisplayBook( book );

}

int main()
{
    //TestBookClass();
    //TestLibraryClass();

    Library testLibrary;
    testLibrary.Run();
    return 0;
}
