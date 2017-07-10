
#pragma once
#include <iostream>
#include <string>
#include <algorithm> //for min/max
#include <stdlib.h> //for rand
using namespace std;

void DisplayPetStats(string petName, int hungerPercent, int happinessPercent, int healthPercent)
{
	cout << "Name: \t" << petName << endl
		<< "Hunger: \t" << hungerPercent << "%" << endl
		<< "Happiness: \t" << happinessPercent << "%" << endl
		<< "Health: \t" << healthPercent << "%" << endl;

}

void DisplayMainMenu()
{
	cout << endl << "1. Feed pet" << endl
		<< "2. Play with pet" << endl
		<< "3. Heal pet" << endl
		<< "4. Quit" << endl << endl;
}

void DrawPet(int healthPercent)
{
	if (healthPercent > 75)
	{
		cout << "(^.^)" << endl;
	}
	else if (healthPercent >= 50)
	{
		cout << "(o.o)" << endl;
	}
	else if (healthPercent >= 25)
	{
		cout << "(O.o)" << endl;
	}
	else
	{
		cout << "(p.q)" << endl;
	}
}

int GetChoice(int min, int max)
{
	int choice;
	do
	{
		cout << ">>";
		cin >> choice;

		if (choice < min || choice > max)
		{
			cout << "Please choose an option from the list from " << min << " to " << max << "." << endl;
		}

	} while (choice < min || choice > max);

	return choice;
}

void UpdatePet(int& hungerPercent, int& happinessPercent, int& healthPercent)
{
	//Set hunger for new cycle
	hungerPercent += 5;

	//Check hunger to modify happiness and health
	if (hungerPercent > 75)
	{
		happinessPercent -= 10;
		healthPercent -= 10;
	}
	else if (hungerPercent > 50)
	{
		happinessPercent -= 5;
		healthPercent -= 5;
	}
	else if (hungerPercent > 25)
	{
		happinessPercent -= 2;
		healthPercent -= 2;
	}

	//Verify that hunger, happiness, and health are all valid values, and correct if they are not.
	hungerPercent = min(100, hungerPercent);
	happinessPercent = max(0, happinessPercent);
	healthPercent = max(0, healthPercent);
}

void Feed(int& hungerPercent)
{
	//Decrease hunger
	hungerPercent -= 8;

	//Make sure hunger is not less than 0
	hungerPercent = max(0, hungerPercent);
}

void Play(int& happinessPercent)
{
	//Increase happiness
	happinessPercent += 5;

	//Verify happiness doesn't exceed 100
	happinessPercent = min(100, happinessPercent);
}

void Heal(int& healthPercent)
{
	//Increase health
	healthPercent += 5;

	//Make sure health doesn't exceed 100
	healthPercent = min(100, healthPercent);
}

void FeedText(const string petName)
{
    cout << endl << "\\ (0.0) /" << endl;
    cout << petName;
    switch (rand() % 4) //Break up the monotony
            {
            case 0:
                cout << " snarfs down the food you gave it!" << endl;
                break;
            case 1:
                cout << " giggles with delight as it munches away!" << endl;
                break;
            case 2:
                cout << " gives you a big, toothy grin as it devours its favorite food!" << endl;
                break;
            case 3:
                cout << " daintily nibbles its meal, savoring every bite." << endl;
                break;
            default:
                break;
            }
}

void PlayText(const string petName)
{
    cout << endl << "\\ (^.^) /" << endl;
    cout << petName;

    switch (rand() % 4)
        {
        case 0:
            cout << " seems overjoyed to play with you!" << endl;
            break;

        case 1:
            cout << " delights in games of tickling!" << endl;
            break;

        case 2:
            cout << " is awestruck by your ability to pop in and out of existence during peekaboo!" << endl;
            cout << "(Object permanence apparently isn\'t " << petName << "\'s strong suit)." << endl;
            break;

        case 3:
            cout << " gives you a run for you money in a game of Old Maid." << endl;
            break;

        default:
            break;
        }
}

void HealText(const string petName) //Provides a pseudo-random text to go along with healing.
{
    cout << endl << "(^.*)" << endl;
    cout << petName;

    switch (rand() % 4)
        {
        case 0:
            cout << " takes its bandage and turns it into a pirate's eye-patch! Yarr!" << endl;
            break;
        case 1:
            cout << " is so covered with wrappings you might easily mistake it for the Mummy!" << endl;
            break;
        case 2:
            cout << "\'s insistence on a neck brace for a paper cut instills concerns of malingering." << endl;
            break;
        case 3:
            cout << " waves your assistance off. It's fine. Really." << endl;
            break;
        default:
            break;
        }
}
