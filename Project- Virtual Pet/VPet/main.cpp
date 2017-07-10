#include <iostream>
#include <string>
#include <stdlib.h>
#include "pa_virtual_pet.hpp"
using namespace std;

int main()
{
	string petName;
	int hungerPercent = 0;
	int happinessPercent = 100;
	int healthPercent = 100;

	cout << "What would you like to call your pet?" << endl;
	cin >> petName;

	cout << endl;

	bool quit = false;

	while( !quit )
	{
		cout << endl;
		UpdatePet(hungerPercent, happinessPercent, healthPercent);
		DrawPet(happinessPercent);
		DisplayPetStats(petName, hungerPercent, happinessPercent, healthPercent);

		if (healthPercent <= 0)
		{
			cout << "Your pet has died.";
			break;
		}

		DisplayMainMenu();

		int choice = GetChoice(1, 4);

		switch (choice)
		{
		case 1:
			Feed(hungerPercent);
            FeedText(petName);
			break;

		case 2:
			Play(happinessPercent);
			PlayText(petName);
			break;

		case 3:
			Heal(healthPercent);
            HealText(petName);
			break;
		case 4:
			quit = true;
		}
	}

	return 0;


}
