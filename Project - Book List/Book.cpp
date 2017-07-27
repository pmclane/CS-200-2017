#include <iostream>
#include <string>
#include "Book.hpp"
void Book::DisplayBook()
 {
    cout <<  m_title << " by " << m_author << endl
    << GetPurchaseStatusString() << endl
    << GetReadingStatusString() << endl;
 }

 void Book::SetBookInfo( string title, string author )
 {
     m_title = title;
     m_author = author;
 }

string Book::GetAuthor()
{
    return m_author;
}

string Book::GetTitle()
{
    return m_title;
}

int Book::GetPurchaseStatus()
{
    return m_purchaseStatus;
}

string Book::GetPurchaseStatusString()
{
    switch ( m_purchaseStatus )
    {
    case OWNED:
        return "Owned";
        break;
    case WISHLIST:
        return "Wishlist";
        break;
    default:
        return "Error: Purchase Status undefined";
        break;
    }
}
void Book::SetPurchaseStatus( PurchaseStatus ps )
{
    m_purchaseStatus = ps;
}

int Book::GetReadingStatus()
{
    return m_readingStatus;
}
string Book::GetReadingStatusString()
{
     switch ( m_readingStatus )
    {
    case NOT_STARTED:
        return "Not started";
        break;
    case READING:
        return "Reading";
        break;
    case FINISHED:
        return "Finished";
        break;
    default:
        return "Error: Reading Status undefined";
        break;
    }

}

void Book::SetReadingStatus( ReadingStatus rs )
{
    m_readingStatus = rs;
}
