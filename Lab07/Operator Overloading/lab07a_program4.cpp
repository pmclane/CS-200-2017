#include <iostream>
using namespace std;

#include "CoordinatePair.hpp"

int MainMenu()
{
	cout << endl << "MAIN MENU" << endl;
	cout << "1. Set coordinate pair 1" << endl;
	cout << "2. Set coordinate pair 2" << endl;
	cout << "3. Display the coordinate pairs" << endl << endl;

	cout << "4. ADD coordinate pairs" << endl;
	cout << "5. SUBTRACT coordinate pairs" << endl << endl;

	cout << "6. Are they equal?" << endl << endl;

	cout << "7. Exit" << endl << endl;

	cout << ">> ";
	int choice;
	cin >> choice;

	cout << endl << endl;

	return choice;
}

int main()
{
	CoordinatePair coord1, coord2, result;

	while (true)
	{
		int choice = MainMenu();

		if (choice == 1)
		{
			cout << "Enter x and y for coordinate 1: ";
			cin >> coord1;
		}

		else if (choice == 2)
		{
			cout << "Enter x and y for coordinate 2: ";
			cin >> coord2;
		}

		else if (choice == 3)
		{
			cout << "Coordinate pairs:" << endl;
			cout << "\t" << coord1 << "\n\t" << coord2 << endl;
		}

		else if (choice == 4)
		{
			result = coord1 + coord2;
			cout << coord1 << " + " << coord2 << " = " << result << endl;
		}

		else if (choice == 5)
		{
			result = coord1 - coord2;
			cout << coord1 << " - " << coord2 << " = " << result << endl;
		}

		else if (choice == 6)
		{
			if (coord1 == coord2)
			{
				cout << "The coordinate pairs are equal" << endl;
			}
			else if (coord1 != coord2)
			{
				cout << "The coordinate pairs are not equal" << endl;
			}
		}

		else if (choice == 7)
		{
			cout << "Bye" << endl;
			break;
		}
	}

	return 0;
}