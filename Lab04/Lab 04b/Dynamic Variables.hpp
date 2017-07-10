#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

string GiveNumEnding(int num)
{
    if (num % 100 < 20 && num % 100 > 3)
    {
        return "th";
    }
    else if (num % 10 == 1)
    {
        return "st";
    }
    else if (num % 10 == 2)
    {
        return "nd";
    }
    else if (num %10 == 3)
    {
        return "rd";
    }
    else
    {
        return "th";
    }
}
void DynamicVariables()
{
	float* myFloat = nullptr;
	int* myInt = nullptr;
	string* myStr = nullptr;

	myFloat = new float;
	myInt = new int;
	myStr = new string;

	*myFloat = 199.99;
	*myInt = 20;
	*myStr = "Philip McLane";

	cout << *myInt << "\t" << *myStr << "\t" << *myFloat << endl << endl;

	float* myFloatArr = nullptr;
	int* myIntArr = nullptr;
	string* myStrArr = nullptr;

	int size = 0;

	cout << "How large is your array?" << endl;
	cin >> size;

	myFloatArr = new float[size];
	myIntArr = new int[size];
	myStrArr = new string[size];

	for (int i = 0; i < size; i++)
    {
        cout << "Please enter your " << i+1 << GiveNumEnding(i+1) << " integer value: ";
        cin >> myIntArr[i];

        cout << "Please enter your " << i+1 << GiveNumEnding(i+1) << " string value: ";
        cin >> myStrArr[i];

        cout << "Please enter your " << i+1 << GiveNumEnding(i+1) << " float value: ";
        cin >> myFloatArr[i];
        cout << endl;
    }

    cout << "This is the data you entered:" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << endl << myIntArr[i] << "\t" << myStrArr[i] << "\t" << myFloatArr[i] << endl;
    }
	//Delete variables and set pointers to null.
	delete myFloat;
	myFloat = nullptr;

	delete myInt;
	myInt = nullptr;

	delete myStr;
	myStr = nullptr;

	delete[] myFloatArr;
	delete[] myIntArr;
	delete[] myStrArr;


}
