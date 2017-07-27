#ifndef _BOOK_HPP
#define _BOOK_HPP
#include <string>
using namespace std;

//I hate 0 values in menus, so I added placeholders and incremented the remaining values.
enum ReadingStatus { PLACEHOLDER1 = 0, NOT_STARTED = 1, READING = 2, FINISHED = 3 };
enum PurchaseStatus { PLACEHOLDER2 = 0, OWNED = 1, WISHLIST = 2 };

class Book
{
public:
    void SetBookInfo(string title, string author);
    void SetPurchaseStatus( PurchaseStatus ps );
    void SetReadingStatus( ReadingStatus rs );
    void DisplayBook();

    string GetAuthor();
    string GetTitle();

    int GetPurchaseStatus();
    string GetPurchaseStatusString();

    int GetReadingStatus();
    string GetReadingStatusString();

private:
    string m_title;
    string m_author;
    ReadingStatus m_readingStatus;
    PurchaseStatus m_purchaseStatus;

};


#endif // _BOOK
