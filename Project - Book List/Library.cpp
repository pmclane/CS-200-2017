#include "Library.hpp"
#include <iostream>
#include <fstream>

///BASIC FUNCTIONS
Library::Library()
{   m_bookList = nullptr;
    m_arraySize = 0;
    m_bookCount = 0;
    AllocateMemory(10);
}

Library::~Library()
{
    DeallocateMemory();
}

void Library::AllocateMemory( int arraySize )
{
    DeallocateMemory();
    m_bookList = new Book[ arraySize ];
    m_arraySize = arraySize;
}

void Library::DeallocateMemory()
{
    if ( m_bookList != nullptr )
    {
        delete[] m_bookList;
        m_bookList = nullptr;
        m_bookCount = 0;
        m_arraySize = 0;
    }
}
void Library::ResizeArray()
{
    Book* biggerArray = new Book[ m_arraySize + 10 ];

    for ( int i = 0; i < m_arraySize; i++ )
    {
        biggerArray[i] = m_bookList[i];
    }

    delete[] m_bookList;
    m_bookList = biggerArray;
    m_arraySize += 10;
}

int Library::GetArraySize()
{
    return m_arraySize;
}

int Library::GetBookCount()
{
    return m_bookCount;
}

bool Library::IsArrayFull()
{
    return ( m_arraySize == m_bookCount );
}

///SECONDARY FUNCTIONS
void Library::DisplayBooksWithIndex()
{
    for (int i = 0; i < m_bookCount; i++)
    {
        cout << i+1 << ". ";
        m_bookList[i].DisplayBook();
    }
}

void Library::ClearScreen()
{
    #if _WIN32
    system("CLS");

    #elif linux
    system("clear");
    #endif // _WIN32
}

///User functions
void Library::Run()
{
    MainMenu();
}

void Library::MainMenu()
{
    LoadData();
    bool loop = true;
    int userInput;
    while(loop)
    {

        cout << "--------------------------" << endl;
        cout << "|  Library Main Menu     |" << endl;
        cout << "--------------------------" << endl;
        cout << "| 1. Add Book            |" << endl;
        cout << "| 2. Update Book         |" << endl;
        cout << "| 3. View Stats          |" << endl;
        cout << "| 4. View All Books      |" << endl;
        cout << "| 5. Create Wishlist     |" << endl;
        cout << "| 6. Create Reading List |" << endl;
        cout << "| 7. Create Book List    |" << endl;
        cout << "| 8. Sort by Author      |" << endl;
        cout << "| 9. Sort by Title       |" << endl;
        cout << "| 10. Clear Screen       |" << endl;
        cout << "| 11. Save and Quit      |" << endl;
        cout << "--------------------------" << endl;
        cout << endl << "What do you want to do?" << endl;

        cin >> userInput;

        switch ( userInput )
        {
        case 1:
            NewBook();
            break;

        case 2:
            UpdateBook();
            break;

        case 3:
            ClearScreen();
            ViewStats();
            break;

        case 4:
            ViewAllBooks();
            break;

        case 5:
            CreateWishlist();
            break;

        case 6:
            CreateReadingList();
            break;

        case 7:
            CreateBookList();
            break;

        case 8:
            Alphabetize('A');
            break;

        case 9:
            Alphabetize('T');
            break;

        case 10:
            ClearScreen();
            break;

        case 11:
            loop = false;
            break;

        default:
            break;
        }
    }
    SaveData();

}

///MAIN MENU FUNCTIONS
void Library::NewBook()
{
    if (IsArrayFull())
    {
        ResizeArray();
    }

    string title, author;
    int rs, ps;

    cin.ignore();
    cout << "Title: ";
    getline( cin, title );
    cout << "Author's name: ";
    getline( cin, author );
    m_bookList[m_bookCount].SetBookInfo( title, author );

    cout << "Please select reading status:" << endl
        << "1. Not started" << endl
        << "2. Reading" << endl
        << "3. Finished" << endl;
    cin >> rs;

    m_bookList[m_bookCount].SetReadingStatus( ReadingStatus (rs) );

    ///Request Purchase status
    cout << "Please select purchase status:" << endl
        << "1. Owned" << endl
        << "2. On Wishlist" << endl;
    cin >> ps;
    m_bookList[ m_bookCount ].SetPurchaseStatus( PurchaseStatus (ps) );

    m_bookCount++;

    string moreNewBooks = " adding books to the library";

    if ( Continue( moreNewBooks ) )
    {
        NewBook();
    }

}

void Library::UpdateBook()
{
    if (m_bookCount == 0 )
    {
        cout << "There are no books in this library." << endl;
        Pause();
        return;
    }
    int bookIndex = 0;
    int choice;
    string input;
    string functionName = " updating";

    DisplayBooksWithIndex();

    cout << endl;

    do
    {
        cout << "Which book would you like to update?" << endl;
        cin >> bookIndex;
        bookIndex--;
    } while( bookIndex < 0 || bookIndex > m_bookCount );

    cout << "What would you like to do?" << endl
        << "1. Update Title" << endl
        << "2. Update Author" << endl
        << "3. Update Reading Status" << endl
        << "4. Update Purchase Status" << endl
        << "5. Cancel" << endl;
    cin >> choice;

    switch ( choice )
        {
        case 1:
            cout << "What is the new title?" << endl;
            cin.ignore();
            getline(cin, input);
            m_bookList[bookIndex].SetBookInfo( input, m_bookList[bookIndex].GetAuthor() );

            if ( Continue( functionName ) )
            {
                UpdateBook();
            }
            break;

        case 2:
            cout << "Who is the new author?" << endl;
            cin.ignore();
            getline(cin, input);
            m_bookList[bookIndex].SetBookInfo( m_bookList[bookIndex].GetTitle(), input );

            if ( Continue( functionName ) )
            {
                UpdateBook();
            }
            break;

        case 3:

            cout << "Please select a reading status:" << endl
                << "1. Not started" << endl
                << "2. Reading" << endl
                << "3. Finished" << endl;
            cin >> choice;
            m_bookList[bookIndex].SetReadingStatus( ReadingStatus (choice));

            if ( Continue( functionName ) )
            {
                UpdateBook();
            }
            break;

        case 4:
            cout << "Please select a purchase status:" << endl
                << "1. Owned" << endl
                << "2. On Wishlist" << endl;
            cin >> choice;
            m_bookList[bookIndex].SetPurchaseStatus( PurchaseStatus (choice));

            if ( Continue( functionName ) )
            {
                UpdateBook();
            }
            break;
        case 5:
            break;

        default:
            break;
        }

}

void Library::ViewStats()
{
    cout << "---------------------" << endl;
    cout << "|  View Book Stats  |" << endl;
    cout << "---------------------" << endl;

    int owned, wishCount, finCount, readingCount, notStarted;
    owned = 0;
    wishCount = 0;
    finCount = 0;
    readingCount = 0;
    notStarted = 0;

    for ( int i = 0; i < m_bookCount; i++ )
    {
        if ( m_bookList[i].GetPurchaseStatus() == OWNED )
        {
            owned++;
        }
        else
        {
            wishCount++;
        }

        if ( m_bookList[i].GetReadingStatus() == NOT_STARTED )
        {
            notStarted++;
        }
        else if ( m_bookList[i].GetReadingStatus() == READING )
        {
            readingCount++;
        }
        else
        {
            finCount++;
        }
    }

    cout << "Total Books:\t\t\t" << m_bookCount << endl;
    cout << "Books Owned:\t\t\t" << owned << endl;
    cout << "Books on Wishlist:\t\t" << wishCount << endl;
    cout << "Books Finished:\t\t\t" << finCount << endl;
    cout << "Books Currently Reading:\t" << readingCount << endl;
    cout << "Books Not Started:\t\t" << notStarted << endl;

    Pause();

}

void Library::ViewAllBooks()
{
    cout << "--------------------" << endl;
    cout << "|  View All Books  |" << endl;
    cout << "--------------------" << endl;
    cout << endl;
    for (int i = 0; i < m_bookCount; i++)
    {
        m_bookList[i].DisplayBook();
        cout << endl;
    }

    Pause();
}

void Library::CreateWishlist()
{
    ofstream output;
    int newCount = 1;
    output.open( "Wishlist.txt" );
    output << "Books On Wishlist:" << endl;

    for (int i = 0; i < m_bookCount; i++)
    {
        if ( m_bookList[ i ].GetPurchaseStatus() == WISHLIST )
        {
            output << "Title: " << m_bookList[ i ].GetTitle() << endl;
            output << "Author: " << m_bookList[ i ].GetAuthor() << endl;
            output << "Reading? " << m_bookList[ i ].GetReadingStatusString() << endl;
            output << endl;

            newCount++;
        }
    }
    output.close();
}

void Library::CreateReadingList()
{
    ofstream output;
    int newCount = 1;
    output.open( "Reading.txt" );
    output << "List of Books Currently Reading:" << endl;

    for (int i = 0; i < m_bookCount; i++)
    {
        if ( m_bookList[ i ].GetReadingStatus() != FINISHED )
        {

            output << "Title: " << m_bookList[ i ].GetTitle() << endl;
            output << "Author: " << m_bookList[ i ].GetAuthor() << endl;
            output << "Reading? " << m_bookList[ i ].GetReadingStatusString() << endl;
            output << "Owned? " << m_bookList[ i ].GetPurchaseStatusString() << endl;
            output << endl;
            newCount++;
        }
    }
    output.close();
}

void Library::CreateBookList()
{

    ofstream output;
    output.open( "book list.txt" );
    output << "My Library:" << endl;
    for (int i = 0; i < m_bookCount; i++)
    {
        output << "Title: " << m_bookList[ i ].GetTitle() << endl;
        output << "Author: " << m_bookList[ i ].GetAuthor() << endl;
        output << "Reading? " << m_bookList[ i ].GetReadingStatusString() << endl;
        output << "Owned? " << m_bookList[ i ].GetPurchaseStatusString() << endl;
        output << endl;

    }
    output.close();
}

void Library::Alphabetize( char authorOrTitle )
{
    string currentString;
    string nextString;
    int currentSize;
    int nextSize;
    switch ( authorOrTitle )
    {
    case 'A':
        for (int index = 0; index < m_bookCount - 1; index++)
        {
            currentString = m_bookList[index].GetAuthor();
            nextString = m_bookList[index+1].GetAuthor();

            currentSize = currentString.length();
            nextSize = nextString.length();

            if ( currentSize <= nextSize )
            {
                for (int i = 0; i < currentSize; i++)
                {
                    if (currentString[i] < nextString[i])
                    {
                        i = currentSize;
                    }
                     else if ( currentString[i] > nextString[i] )
                    {
                        swap( m_bookList[index], m_bookList[index+1]);
                        i = currentSize;
                        index = -1;
                    }
                    else
                    {
                        continue;
                    }
                }
            }
            else
            {
                for (int i = 0; i < nextSize; i++)
               {

                    if (currentString[i] < nextString[i])
                    {
                        i = nextSize;
                    }
                    else if ( currentString[i] > nextString[i] )
                    {
                        swap( m_bookList[index], m_bookList[index+1]);
                        i = nextSize;
                        index = -1;
                    }
                    else
                    {
                        continue;
                    }
               }
            }
        }
        break;

    case 'T':
         for (int index = 0; index < m_bookCount - 1; index++)
        {
            currentString = m_bookList[index].GetTitle();
            nextString = m_bookList[index+1].GetTitle();

            currentSize = currentString.length();
            nextSize = nextString.length();

             if ( currentSize <= nextSize )
            {
                for (int i = 0; i < currentSize; i++)
                {
                    if (currentString[i] < nextString[i])
                    {
                        i = currentSize;
                    }
                     else if ( currentString[i] > nextString[i] )
                    {
                        swap( m_bookList[index], m_bookList[index+1]);
                        i = currentSize;
                        index = -1;
                    }
                    else
                    {
                        continue;
                    }
                }
            }
            else
            {
                for (int i = 0; i < nextSize; i++)
               {

                    if (currentString[i] < nextString[i])
                    {
                        i = nextSize;
                    }
                    else if ( currentString[i] > nextString[i] )
                    {
                        swap( m_bookList[index], m_bookList[index+1]);
                        i = nextSize;
                        index = -1;
                    }
                    else
                    {
                        continue;
                    }
               }

            }
        }
        break;


    }
}

///MAIN MENU HELPER FUNCTIONS
void Library::SaveData()
{
    ofstream output;
    output.open( "books.txt" );

    for (int i = 0; i < m_bookCount; i++)
    {
        output << "BOOK" << i+1 << endl;
        output << m_bookList[ i ].GetTitle() << endl;
        output << m_bookList[ i ].GetAuthor() << endl;
        output << m_bookList[ i ].GetReadingStatus() << endl;
        output << m_bookList[ i ].GetPurchaseStatus() << endl;

    }
    output.close();
}

void Library::LoadData()
{
    ifstream input;

    input.open( "books.txt" );

    string header;
    string title;
    string author;
    int rs;
    int ps;

    while (input >> header)
    {
        input.ignore();
        getline( input, title );
        getline( input, author );
        input >> rs;
        input >> ps;
        if ( IsArrayFull() )
        {
            ResizeArray();
        }

        m_bookList[ m_bookCount ].SetBookInfo( title, author );
        m_bookList[ m_bookCount ].SetReadingStatus ( ReadingStatus (rs) );
        m_bookList[ m_bookCount ].SetPurchaseStatus( PurchaseStatus (ps) );

        m_bookCount++;
    }
    input.close();
}

void Library::Pause()
{
    cout << endl << endl;
    cout << "Press any letter, then Enter to continue..." << endl;
    char hold;
    cin >> hold;
    ClearScreen();
}

bool Library::Continue( string continueThis )
{
    char input;
    cout << "Would you like to continue"<< continueThis <<"? (y to continue)" << endl;
    cin >> input;

    if ( input == 'y' || input == 'Y')
    {
        return true;
    }
    else
    {
        ClearScreen();
        return false;
    }
}

void Library::Swap( Book &first, Book &second )
{
    string author = first.GetAuthor();
    string title = first.GetTitle();
    int ps = first.GetPurchaseStatus();
    int rs = first.GetReadingStatus();

    first.SetBookInfo( second.GetTitle(), second.GetAuthor() );
    first.SetPurchaseStatus( PurchaseStatus ( second.GetPurchaseStatus() ) );
    first.SetReadingStatus( ReadingStatus ( second.GetReadingStatus() ) );

    second.SetBookInfo( title, author);
    second.SetPurchaseStatus( PurchaseStatus (ps) );
    second.SetReadingStatus( ReadingStatus (rs) );
}
