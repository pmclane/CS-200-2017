#ifndef _KITTEN_HPP
#define _KITTEN_HPP

#include <string>
#include <iostream>
using namespace std;
class Kitten
{
public:
	Kitten(string name);
	void Display();

private:
	string m_name;
	static int m_kittenCount;
};

#endif
