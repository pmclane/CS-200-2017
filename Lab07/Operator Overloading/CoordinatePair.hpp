#ifndef _COORD_PAIR_HPP
#define _COORD_PAIR_HPP

#include <iostream>
using namespace std;

class CoordinatePair
{
public:
	// Math operators
	friend CoordinatePair operator+(const CoordinatePair& item1, const CoordinatePair& item2);
	friend CoordinatePair operator-(const CoordinatePair& item1, const CoordinatePair& item2);

	// Relational operators
	friend bool operator==(const CoordinatePair& item1, const CoordinatePair& item2);
	friend bool operator!=(const CoordinatePair& item1, const CoordinatePair& item2);

	// Stream operators
	friend ostream& operator<<(ostream& out, CoordinatePair& item);
	friend istream& operator >> (istream& in, CoordinatePair& item);

private:
	float m_x, m_y;
};

#endif