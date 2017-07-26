#ifndef _BUTTON_HPP
#define _BUTTON_HPP

#include <string>
#include <iostream>
using namespace std;

class Button
{
public:
	void SetText(string text);
	void Draw() const;

private:
	string m_text;
};

#endif