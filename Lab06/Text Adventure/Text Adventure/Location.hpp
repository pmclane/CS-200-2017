#ifndef _LOCATION_HPP
#define _LOCATION_HPP

#include <iostream>
#include <string>
using namespace std;

class Location
{
public:
    Location();
    void SetInfo( string name, string description );
    void Display();
    string GetName();
    string GetNeighborName(string direction); //Added this to allow locations to tell about their neighbors
    void SetNeighbor( string direction, Location* ptrLocation );
    Location* GetNeighbor( string direction );

private:
    string m_name;
    string m_description;

    Location* m_ptrToNorth;
    Location* m_ptrToSouth;
    Location* m_ptrToEast;
    Location* m_ptrToWest;
};

#endif
