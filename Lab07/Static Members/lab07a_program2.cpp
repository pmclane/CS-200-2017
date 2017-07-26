#include <iostream>
using namespace std;

#include "Kitten.hpp"

int main()
{
	Kitten happyCat("Fluffy");
	happyCat.Display();

	Kitten angryCat("Stripey");
	angryCat.Display();

	Kitten sadCat("Sluggy");
	sadCat.Display();

	Kitten curiousCat("Spotty");
	curiousCat.Display();

	return 0;
}