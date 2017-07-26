#include "kitten.hpp"
// This is needed for our static member variable
int Kitten::m_kittenCount = 0;
Kitten::Kitten(string name)
{
	m_name = name;
	m_kittenCount++;
}

void Kitten::Display()
{
	cout << "Kitten: " << m_name << ", " << "Kitten Count: " << m_kittenCount << endl;
}