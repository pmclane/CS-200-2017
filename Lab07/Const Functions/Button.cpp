#include "Button.hpp"

void BorderBuilder(int length)
{
	for (int i = 0; i < length; i++)
	{
		cout << "*";
	}
	cout << endl;
}
void Button::SetText(string text)
{
	m_text = text;
}

void Button::Draw() const
{
	int length = m_text.length() + 4;

	BorderBuilder(length);
	cout << "* " << m_text << " *" << endl;
	BorderBuilder(length);
}