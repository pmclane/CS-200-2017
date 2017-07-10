#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void CityDistance()
{
    cout << endl << "Choose a starting point:" << endl
        << "1. Kansas City" << endl
        << "2. Seattle" << endl;

    int city;
    cin >> city;
    cin.ignore();

    string cityName;

    ifstream input;

    if ( city == 1 )
    {
        input.open( "from_kc.txt" );
        cityName = "Kansas City";
    }
    else
    {
        input.open( "from_seattle.txt" );
        cityName = "Seattle";
    }

    int locationCount = 0;
    string * locations;
    int * distances;

    // Load in number of locations
    input >> locationCount;

    // Allocate memory for locations and distances
    locations = new string[locationCount];
    distances = new int[locationCount];

    // Use a for loop to load in all the data from text files
    for (int i = 0; i < locationCount; i++)
    {
        input >> locations[i] >> distances[i];
    }

    // Display all the data to the screen with cout
    cout << endl << "Distance from " << cityName << ":" << endl << endl;

    for (int i = 0; i < locationCount; i++)
    {
        cout << locations[i] << " is " << distances[i] << " miles from " << cityName << "." << endl;
    }
    cout << endl;
    // After the for loop, free the memory of locations and distances.
    delete[] locations;
    delete[] distances;

    input.close();
}
