#include <iostream>
#include "Dynamic Variables.hpp"
#include "Lotto Numbers.hpp"
#include "Buddy Builder.hpp"
#include "Reading Text.hpp"
#include "Employees and Managers.hpp"
using namespace std;

int main()
{

	int choice = '1';

	while (choice != 6)
	{
	    cout << "Choose a program to run: " << endl;
	    cout << "1. Dynamic Variables" << endl;
	    cout << "2. Lottery Numbers" << endl;
	    cout << "3. Buddy Building" << endl;
	    cout << "4. City Distance" << endl;
	    cout << "5. Employees and Managers" << endl;
	    cout << "6. Quit" << endl;
	    cin >> choice;

	    switch(choice)
	    {
        case 1:
            cout << endl;
            DynamicVariables();
            cout << endl;
            break;

	    case 2:
	        cout << endl;
	        LottoNumbers();
	        cout << endl;
	        break;

        case 3:
            cout << endl;
            BuildABuddy();
            cout << endl;
            break;

        case 4:
            cout << endl;
            CityDistance();
            cout << endl;
            break;

        case 5:
            cout << endl;
            EmployeesAndManagers();
            cout << endl;
            break;

        case 6:
            //Quit choice
            break;

        default:
            cout << "Choice not implemented." << endl << endl;
            break;

	    }
	}

	return 0;
}
