#ifndef _GAME_HPP
#define _GAME_HPP

#include <iostream>
#include <string>
using namespace std;

#include "Location.hpp"

class Game
{
public:
    Game();
    void Run();
    char GetChoice();
    void TryToMove( char direction );

private:
    void SetupLocations();

    Location locations[40];
    Location* ptrStart;
    Location* ptrEnd;
    Location* ptrCurrent;
};

#endif
