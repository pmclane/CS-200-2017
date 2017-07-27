#ifndef _LIBRARY_HPP
#define _LIBRARY_HPP
#include "Book.hpp"

class Library
{
public:
    ///Basic Functions
    Library();
    ~Library();
    void AllocateMemory( int arraySize );
    void DeallocateMemory();
    void ResizeArray();
    int GetArraySize();
    int GetBookCount();
    bool IsArrayFull();

    ///Secondary Functions
    void DisplayBooksWithIndex();
    void ClearScreen();

    ///Startup Functions
    void Run();
    void MainMenu();

    ///Main Menu Functions
    void NewBook();
    void UpdateBook();
    void ViewStats();
    void ViewAllBooks();
    void CreateWishlist();
    void CreateReadingList();
    void CreateBookList();
    void Alphabetize(char authorOrTitle);

    ///Main Menu Helper Functions
    void SaveData();
    void LoadData();
    void Pause();
    void Swap( Book &first, Book &second );
    bool Continue( string continueThis );




private:
    Book* m_bookList;
    int m_arraySize;
    int m_bookCount;

};
#endif // _LIBRARY_HPP
