#include "CoordinatePair.hpp"

// Math operators
CoordinatePair operator+(const CoordinatePair& item1, const CoordinatePair& item2)
{
	CoordinatePair sum;

	// do the math
	sum.m_x = item1.m_x + item2.m_x;
	sum.m_y = item1.m_y + item2.m_y;

	return sum;
}

CoordinatePair operator-(const CoordinatePair& item1, const CoordinatePair& item2)
{
	CoordinatePair difference;

	// do the math
	difference.m_x = item1.m_x - item2.m_x;
	difference.m_y = item1.m_y - item2.m_y;

	return difference;
}

// Relational operators
bool operator==(const CoordinatePair& item1, const CoordinatePair& item2)
{
	return (item1.m_x == item2.m_x && item1.m_y == item2.m_y);
}

bool operator!=(const CoordinatePair& item1, const CoordinatePair& item2)
{
	return !(item1.m_x == item2.m_x && item1.m_y == item2.m_y);
}

// Stream operators
ostream& operator<<(ostream& out, CoordinatePair& item)
{
	out << "(" << item.m_x << "," << item.m_y << ")";
	return out;
}

istream& operator >> (istream& in, CoordinatePair& item)
{
	in >> item.m_x >> item.m_y;
	return in;
}