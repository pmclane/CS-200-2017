#include <iostream>
#include <string>
#include <cmath> // needed for square root
using namespace std;

float GetDistance(float x1, float y1, float x2, float y2)
{
	float distance;
	float deltaX = x1 - x2; //Define differences to make code less messy below
	float deltaY = y1 - y2;

	distance = sqrt((deltaX * deltaX) + (deltaY * deltaY));

	return distance;
}
int main()
{
	while (true)
	{
		float x1, y1, x2, y2;

		cout << "First coordinate pair, enter x and y: ";
		cin >> x1 >> y1;

		cout << "Second coordinate pair, enter x and y: ";
		cin >> x2 >> y2;

		float distance = GetDistance(x1, y1, x2, y2);
		cout << "Distance: " << distance << endl;

		cout << endl << endl;
	}

	return 0;
}