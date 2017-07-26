#include <iostream>
using namespace std;

#include "Button.hpp"

int main()
{
	Button btn;
	btn.SetText("Button!");
	btn.Draw();

	btn.SetText("Another Button!");
	btn.Draw();

	return 0;
}