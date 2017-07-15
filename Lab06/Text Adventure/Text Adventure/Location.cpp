#include "Location.hpp"

Location::Location()	// constructor
{
    m_ptrToNorth = nullptr;
    m_ptrToSouth = nullptr;
    m_ptrToEast = nullptr;
    m_ptrToWest = nullptr;
}

void Location::SetInfo( string name, string description )
{
    // Set m_name and m_description
    m_name = name;
    m_description = description;
}

string Location::GetName()
{
    return m_name;
}

void Location::Display()
{
    // Display name, description, and what directions have neighbors
    cout << m_name << ":" << endl
        << m_description << endl;
        if(m_ptrToNorth != nullptr)
        {
            cout << "To the north is the " << m_ptrToNorth->GetName() << "." << endl;
        }
        if(m_ptrToSouth != nullptr)
        {
            cout << "To the south is the " << m_ptrToSouth->GetName() << "." << endl;
        }
        if(m_ptrToEast != nullptr)
        {
            cout << "To the east is the " << m_ptrToEast->GetName() << "." << endl;
        }
        if(m_ptrToWest != nullptr)
        {
            cout << "To the west is the " << m_ptrToWest->GetName() << "." << endl;
        }

}

void Location::SetNeighbor( string direction, Location* ptrLocation )
{
    // Set up neighbor in the given direction.
    if (direction == "north")
    {
        m_ptrToNorth = ptrLocation;
    }
    if (direction == "south")
    {
        m_ptrToSouth = ptrLocation;
    }
    if (direction == "east")
    {
        m_ptrToEast = ptrLocation;
    }
    if (direction == "west")
    {
        m_ptrToWest = ptrLocation;
    }
}

Location* Location::GetNeighbor( string direction )
{
    // Return the corresponding location pointer
   if (direction == "north")
    {
        return m_ptrToNorth;
    }
    else if (direction == "south")
    {
        return m_ptrToSouth;
    }
    else if (direction == "east")
    {
        return m_ptrToEast;
    }
    else if (direction == "west")
    {
        return m_ptrToWest;
    }
    else
    {
        return nullptr;
    }

}

string Location::GetNeighborName( string direction )
{
    // Returns neighbor's name for given direction
   if (direction == "north" && m_ptrToNorth != nullptr)
    {
        return m_ptrToNorth->GetName();
    }
    else if (direction == "south" && m_ptrToSouth != nullptr)
    {
        return m_ptrToSouth->GetName();
    }
    else if (direction == "east" && m_ptrToEast != nullptr)
    {
        return m_ptrToEast->GetName();
    }
    else if (direction == "west" && m_ptrToWest != nullptr)
    {
        return m_ptrToWest->GetName();
    }
    else
    {
        cout << endl << endl << "INVALID CALL. Expected valid string:direction. Received " << direction << "." << endl;
        return "";
    }

}
