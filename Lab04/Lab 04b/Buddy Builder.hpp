#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int Choice(int value)
{
	int choice;
	cout << endl << "(Choices are 0 to " << value-1 << "): ";
	cin >> choice;

	if (choice >= value)
	{
		cout << endl << "Don't like the options? No trouble! I'll pick!" << endl;
		return rand() % value;
	}

	return choice;


}

bool Frankenstein(int partSum, int step)
{
	return (partSum % step != 0 || partSum == step);
}
void BuildABuddy()
{
	string ears[3] = { "   ^ ^   ",   "  n   n ",     "  *   *  " };
	string heads[3] = { " ( o_o ) ",   " ( x_x )" ,    " ( >_< ) " };
	string bodies[3] = { "/(     )\\",  "\\(     )/",   "o(     )o" };
	string feet[3] = { "  d   b   ",  "  @   @ ",     "  () () " };

	string * ptrEars = nullptr;
	string * ptrHead = nullptr;
	string * ptrBody = nullptr;
	string * ptrFeet = nullptr;

	int bodyParts = 4;
	int bodyBits = 3;
	int bodyBuild = 0;
	bool frankenstein = false;
	bool myBuddyIsBroken = false;

	for (int i = 0; i < bodyParts; i++)
	{
		cout << endl;
		int choice = 0;
		switch (i)
		{
		case 0:

			cout << "Time to build a buddy! With ears we hear, and here with ears our buddy builds begin!";
			choice = Choice(bodyBits);
			ptrEars = &ears[choice];
			bodyBuild += choice;
			break;

		case 1:
			cout << "Fantastic! A face in place will stave disgrace! Save face; place face! Append!";
			choice = Choice(bodyBits);
			ptrHead = &heads[choice];
			bodyBuild += choice;
			break;

		case 2:
			cout << "You're an amazing buddy builder! Which reminds me, what should the body be?";
			choice = Choice(bodyBits);
			ptrBody = &bodies[choice];
			bodyBuild += choice;
			break;

		case 3:
			cout << "Oh! How could we forget?! The foundation of any buddy: The feet!";
			choice = Choice(bodyBits);
			ptrFeet = &feet[choice];
			bodyBuild += choice;
			break;

			//This switch should never happen, but if it does...
		default:
		    if (myBuddyIsBroken)
            {
                cout << "*KABOOM!!*" << endl << endl << endl;
                cout << "...that wasn't supposed to happen." << endl;

                //Give user point of error.
                cout << "Hmm, broken at step " << i+1 << "." << endl << "Maybe we should build your buddy later." << endl;

                //If I were using dynamic variables, as most of my code implies I might in the future, I would clear memory here.
                //However, if I want that to be effective, I think I need to use either an array of pointers to pointers or a class to store/clear memory.

                return;
            }
			cout << "Oops! Your buddy broke, and we're only allowed to make one buddy per person.";
			cout << "..but that's ok! We'll make an exception! Let's start over!" << endl;

			i = -1;
			bodyBuild = 0;
			myBuddyIsBroken = true;
			break;

		}
		//Is your buddy a monster?
		if (!frankenstein && i > 0)
		{
			frankenstein = Frankenstein(bodyBuild, i + 1);
		}
	}
	if (frankenstein)
	{
		cout << endl << "Amazing! You're a veritable Frankenstein!";
	}

	cout << endl << "Here's your buddy!" << endl;
	cout << *ptrEars << endl;
	cout << *ptrHead << endl;
	cout << *ptrBody << endl;
	cout << *ptrFeet << endl << endl;

}
