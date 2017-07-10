#include <iostream>
using namespace std;

// Input: A percent value (0% - 100%, no percent sign though)
// Output: The decimal equivalent (0.0 - 1.0)
float PercentToDecimal(float percent)
{
	float decimal = percent / 100;
	return decimal;
}

int main()
{
	float decimal;
		cout << "Enter an integer 0-100: ";
		cin >> decimal;
		cout << PercentToDecimal(decimal) << endl;

	return 0;
}