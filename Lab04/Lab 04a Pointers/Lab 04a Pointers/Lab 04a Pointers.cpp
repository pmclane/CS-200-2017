#include <iostream>
#include <string>
using namespace std;

void AccessAddresses()
{
	int a = 14;
	float b = 3915.15;
	string c = "string";

	int* ptrInt = nullptr;
	float* ptrFloat = nullptr;
	string* ptrString = nullptr;

	ptrInt = &a;
	ptrFloat = &b;
	ptrString = &c;

	cout << "Int Variable: \t" << a << "\t Address: " << ptrInt << endl;
	cout << "Float Variable: " << b << "\t Address: " << ptrFloat << endl;
	cout << "String Variable: " << c << "\t Address: " << ptrString << endl;
}

void DisplayElementAddresses()
{
	int collatz[] = { 17, 52, 26, 13, 40, 20, 10, 5, 16, 8, 4, 2, 1 };
	int collatzSize = 13;

	int* ptrArray = nullptr;
	int* ptrElement = nullptr;

	ptrArray = collatz;

	for (int i = 0; i < collatzSize; i++)
	{
		ptrElement = &collatz[i];
		cout << "Item " << i  << ": " << *ptrElement << " \t Address: " << ptrElement << endl;
	}
}

void UsePointers()
{
	int a = 14;
	float b = 3915.15;
	string c = "string";

	int* ptrInt = nullptr;
	float* ptrFloat = nullptr;
	string* ptrString = nullptr;

	ptrInt = &a;
	ptrFloat = &b;
	ptrString = &c;

	cout << "Int Variable: \t" << *ptrInt << "\t Address: " << ptrInt << endl;
	cout << "Float Variable: " << *ptrFloat << "\t Address: " << ptrFloat << endl;
	cout << "String Variable: " << *ptrString << "\t Address: " << ptrString << endl;

}

void BytesNum()
{
	bool exit = false;
	char choice = ' ';
	while (!exit)
	{
		cout << "Choose a variable type: [c]har, [d]ouble, [f]loat, [i]nt, e[x]it: ";
		cin >> choice;

		switch (choice)
		{
		case 'c':
			cout << "A character variable is " << sizeof(char) << " bytes." << endl << endl;
			break;
		case 'd':
			cout << "A double variable is " << sizeof(double) << " bytes." << endl << endl;
			break;
		case 'f':
			cout << "A float variable is " << sizeof(float) << " bytes." << endl << endl;
			break;
		case 'i':
			cout << "A integer variable is " << sizeof(int) << " bytes." << endl << endl;
			break;
		case 'x':
			exit = true;
			break;
		default:
			cout << "\'" << choice << "\' was not a listed option" << endl << endl;
		}
	}
}

void Food()
{
	float priceHamburger = 2.14;
	float priceFries = 1.09;
	float priceSalad = 3.42;
	float* ptrPrice = nullptr;
	float taxAmt = 0;

	char choice = 'x';
	bool exit = false;

	while (!exit)
	{
		cout << "Would you like a [h]ambuger, [f]ries, or [s]alad? (type 'x' to cancel)" << endl;
		cin >> choice;

		switch (choice)
		{
		case 'h':
			ptrPrice = &priceHamburger;
			break;

		case 'f':
			ptrPrice = &priceFries;
			break;

		case 's':
			ptrPrice = &priceSalad;
			break;

		case 'x':
			exit = true;
			continue;

		default:
			cout << "Invalid Input." << endl << endl;
			continue;
			
		}

		taxAmt = *ptrPrice * 0.065;
		*ptrPrice += taxAmt;
		cout << "Food Cost: $" << *ptrPrice << endl << endl;
	}
}

void Students()
{
	string students[]{ "James", "Earl", "Joanna" };
	int choice;
	string* ptrStudent = nullptr;

	cout << "Please enter an index of 0, 1, or 2: ";
	cin >> choice;
	ptrStudent = &students[choice];

	cout << "Please enter a name for this student: ";
	cin >> *ptrStudent;

	for (int i = 0; i < 3; i++)
	{
		cout << "Student " << i << ":\t " << students[i] << endl;
	}

}


int main()
{
	cout << "Access Addresses" << endl;
	AccessAddresses();

	cout << endl << endl << "Display Array Element Addresses" << endl;
	DisplayElementAddresses();

	cout << endl << endl << "Using Pointers" << endl;
	UsePointers();

	cout << endl << endl << "Number of Bytes" << endl;
	BytesNum();

	cout << endl << endl << "Food" << endl;
	Food();

	cout << endl << endl << "Students" << endl;
	Students();

	while (true);

	return 0;
}