#include "Location.hpp"

Location::Location()	// constructor
{
	// Initialize all member pointers to nullptr
}

void Location::SetInfo(string name, string description)
{
	// Set m_name and m_description
}

string Location::GetName()
{
	// Return m_name value
}

void Location::Display()
{
	// Display name, description, and what directions have neighbors
}

void Location::SetNeighbor(string direction, Location* ptrLocation)
{
	// Set up neighbor in the given direction.
}

Location* Location::GetNeighbor(string direction)
{
	// Return the corresponding location pointer
}