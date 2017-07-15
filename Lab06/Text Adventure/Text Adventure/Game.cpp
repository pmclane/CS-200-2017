#include "Game.hpp"

Game::Game()
{
    ptrStart = &locations[0];
    ptrEnd = &locations[39];
    ptrCurrent = ptrStart;
    SetupLocations();
}


void Game::TryToMove( char direction )
{
    //Travel North
    if (direction == 'n' && ptrCurrent->GetNeighbor("north") != nullptr)
    {
        cout << "You travel north to " << ptrCurrent->GetNeighborName("north") << "." << endl << endl;
        ptrCurrent = ptrCurrent->GetNeighbor("north");
    }

    //Travel South
    else if (direction == 's' && ptrCurrent->GetNeighbor("south") != nullptr)
    {
        cout << "You travel south to " << ptrCurrent->GetNeighborName("south") << "." << endl << endl;
        ptrCurrent = ptrCurrent->GetNeighbor("south");
    }

    //Travel East
    else if (direction == 'e' && ptrCurrent->GetNeighbor("east") != nullptr)
    {
        cout << "You travel east to " << ptrCurrent->GetNeighborName("east") << "." << endl << endl;
        ptrCurrent = ptrCurrent->GetNeighbor("east");
    }

    //Travel West
    else if (direction == 'w' && ptrCurrent->GetNeighbor("west") != nullptr)
    {
        cout << "You travel west to " << ptrCurrent->GetNeighborName("west") << "." << endl << endl;
        ptrCurrent = ptrCurrent->GetNeighbor("west");
    }

    //If an invalid direction is entered:
    else
    {
        cout << "You can't travel in that direction." << endl << endl;
    }
}

void Game::Run()
{
    while( true )
    {
	// DISPLAY THE CURRENT LOCATION'S INFO HERE
	ptrCurrent->Display();

        if ( ptrCurrent == ptrEnd )
        {
            // End the game
            break;
        }

        char choice = GetChoice();

        if ( choice == 'q' )
        {
            break;
        }

        TryToMove( choice );
    }

    cout << endl << "You've reached your destination!" << endl;
    cout << "You win!" << endl;
}

char Game::GetChoice()
{
    cout << endl << "What do you want to do? (N/S/E/W/Q): ";
    char choice;
    cin >> choice;
    return tolower( choice );
}

void Game::SetupLocations()
{
    // Move your array init stuff from the file with main() to here.

    locations[0].SetInfo( "Alaska", "Denali stands high here in the Alaska Range." );
    locations[1].SetInfo( "The Canadian Northwest Territories", "A frigid wind sweeps south from the Arctic circle." );
    locations[2].SetInfo( "The Northwestern Passages", "Countless islands dot the icy bay." );
    locations[3].SetInfo( "Greenland and Iceland", "The two islands here seem to have swapped names." );
    locations[4].SetInfo( "Scandinavia", "Massive fjords rise from the sea." );
    locations[5].SetInfo( "European Russia", "Dense forests cover the land." );
    locations[6].SetInfo( "Northern Russia", "Permafrost covers the ground." );
    locations[7].SetInfo( "Eastern Siberia", "Taiga cover this land of snow, ice, and swamps." );
    locations[8].SetInfo( "The Northeastern Pacific", "Cruise ships sail by, their passengers watching for auroras." );
    locations[9].SetInfo( "North American Plains and Rockies", "Hundreds of lakes dot the land, with badlands and prairies to the south.");
    locations[10].SetInfo( "North American East", "Five enormous lakes lie here, with North America giving way to the Atlantic to the east.");
    locations[11].SetInfo( "The United Kingdom and Ireland", "Several massive islands rise from the Atlantic which continues to the west.");
    locations[12].SetInfo( "Europe", "Forested lowlands dominate the west, deserts the southeast, with the Mediterranean to the south.");
    locations[13].SetInfo( "Kazakhstan", "Mountains cover much of the land here, though the eastern Xinjiang is a sea of sand.");
    locations[14].SetInfo( "Northeast Asia", "Yellow dust blankets this place in the spring, and three powers squabble over who caused it.");
    locations[15].SetInfo( "Japan", "Rice patties fill the narrow spaces between mountains and cities.");
    locations[16].SetInfo( "The Hawaiian Islands", "Volcanoes rise from the sea, with the sleeping Mauna Kea queen among them.");
    locations[17].SetInfo( "Mexico and Central America", "East of the land here lies the site of an ancient meteor strike.");
    locations[18].SetInfo( "Caribbean", "A multitude of island litter the ocean just beyond the gulf to the west.");
    locations[19].SetInfo( "Western Africa", "Grasslands in the south fade into the Sahara to the north.");
    locations[20].SetInfo( "Central Africa", "Deserts merge into savanna, which in turn fade into dense forest to the south");
    locations[21].SetInfo( "India", "Wet tropics cover the western lands, with the land becoming more arid as one goes inland.");
    locations[22].SetInfo( "Southeast Asia", "Dense rainforest surround the rivers here before falling into the East Sea.");
    locations[23].SetInfo( "Western Polynesia", "Thousands of islands mark the great expanse of the Pacific here.");
    locations[24].SetInfo( "Central Polynesia", "A collection of islands claimed by the French dot the ocean.");
    locations[25].SetInfo( "Southeastern Polynesia", "A remote island is guarded here by many giant stone heads.");
    locations[26].SetInfo( "Central South America", "The Amazon basin dominates the land as far as the eye can see.");
    locations[27].SetInfo( "Eastern Brazil", "Plains and highlands here are bordered by dense forest to the west and ocean to the east.");
    locations[28].SetInfo( "Southern Africa", "Grasslands spread north, with mountains and savanna to the south.");
    locations[29].SetInfo( "Madagascar", "An island once forgotten by time, now famous for fictional talking animals.");
    locations[30].SetInfo( "Western Oceania", "Oceans to the west break upon a desert and grassland continent.");
    locations[31].SetInfo( "Eastern Oceania", "Mountains to the east fall toward desert plains, before reaching a corral filled ocean.");
    locations[32].SetInfo( "South-Central Pacific", "The water grows chilly here, with the Antarctic to the south too cold to brave.");
    locations[33].SetInfo( "South-Southeastern Pacific", "The water is cold, and islands are scarce here.");
    locations[34].SetInfo( "South American South", "Mountains seem to hold back the western ocean, but the land falls away to the south and east.");
    locations[35].SetInfo( "Southern Atlantic", "The South Sandwich islands are here. Sadly, there are no sandwiches.");
    locations[36].SetInfo( "South Africa", "The southern tip of Africa juts out, dividing the Atlantic and Indian Oceans.");
    locations[37].SetInfo( "Southern Indian Ocean", "The French Antarctic Lands stand as a midpoint here between Africa, Australia, and Antarctica.");
    locations[38].SetInfo( "Southeastern Indian Ocean", "Though a desert lies to your north, the water here is uncomfortably cold.");
    locations[39].SetInfo( "Tazmania and New Zealand", "Two islands of fantasy, and while one is Oz, neither is Kansas.");

    for (int i = 0; i < 40; i++)
    {
        //Determine southern neighbor
        if (i < 32)
        {
            locations[i].SetNeighbor( "south",  &locations[i+8] );
        }

        //Northern neighbor
        if (i > 7)
        {
            locations[i].SetNeighbor( "north",  &locations[i-8] );
        }

        //Eastern neighbor (map is a cylinder, so an else is required).
        if ( (i+1) % 8 != 0)
        {
            locations[i].SetNeighbor( "east",   &locations[i+1] );
        }
        else
        {
            locations[i].SetNeighbor( "east",   &locations[i-7] );
        }

        //Western neighbor (map is a cylinder, so an else is required).
        if ( i % 8 != 0)
        {
            locations[i].SetNeighbor( "west",   &locations[i-1] );
        }
        else
        {
            locations[i].SetNeighbor( "west",   &locations[i+7] );
        }
    }
}
