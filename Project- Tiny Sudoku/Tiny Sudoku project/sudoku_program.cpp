#include "sudoku_functions.hpp"

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

#include "utilities.hpp"

/* DON'T MODIFY THIS FILE */

int main()
{
    srand( time( NULL ) );      // Seed random # generator

    bool roundDone = false;
    bool gameDone = false;

    int row, column, number;
    int grid[3][3];

    while ( !gameDone )
    {
        ResetGrid( grid );
        SetRandom( grid, 6 );

        while ( !roundDone )
        {
            DisplayHeader();
            DisplayGrid( grid );

            row = GetRow();
            column = GetColumn();

            while ( CellIsTaken( grid, row, column ) == true )
            {
                cout << endl << "Cell is already taken" << endl << endl;
                row = GetRow();
                column = GetColumn();
            }

            number = GetNumber();

            while ( NumberAlreadyUsed( grid, number ) )
            {
                cout << endl << number << " is already in the grid!" << endl << endl;
                number = GetNumber();
            }

            PlaceNumberInCell( grid, row, column, number );

            Pause();

            if ( AllCellsTaken( grid ) )
            {
                roundDone = true;
            }
        }

        ClearScreen();
        DisplayGrid( grid );

        cout << "All cells filled! Play again? (y/n): ";
        char choice;
        cin >> choice;

        if ( tolower( choice ) == 'n' )
        {
            gameDone = true;
        }
        else
        {
            roundDone = false;
        }
    }

    return 0;
}
