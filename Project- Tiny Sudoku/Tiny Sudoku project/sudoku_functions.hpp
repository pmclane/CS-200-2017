#ifndef _SUDOKU_FUNCTIONS
#define _SUDOKU_FUNCTIONS

#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
using namespace std;

#include "utilities.hpp"

/* MODIFY THESE FUNCTIONS */

void PlaceNumberInCell( int grid[3][3], int row, int column, int number )
{
    grid[row][column] = number;
}

bool CellIsTaken( int grid[3][3], int row, int column )
{
    if ( grid[row][column] == 0 )
    {
        return false;
    }
    else            //Not strictly necessary, but I think this adds clarity.
    {
        return true;
    }
}

void ResetGrid( int grid[3][3] )
{

    for ( int row = 0; row < 3; row++ )
    {
        for ( int column = 0; column < 3; column++ )
        {
            grid[row][column] = 0;
        }
    }

}

bool NumberAlreadyUsed( int grid[3][3], int number )
{
    for ( int row = 0; row < 3; row++ )
    {
        for ( int column = 0; column < 3; column++ )
        {
            if ( grid[row][column] == number )
            {
                return true;
            }
        }
    }
    return false;
}

bool AllCellsTaken( int grid[3][3] )
{
     for ( int row = 0; row < 3; row++ )
    {
        for ( int column = 0; column < 3; column++ )
        {
            if ( grid[row][column] == 0 )
            {
                return false;
            }
        }
    }

    return true;
}

int GetUserInput( int min, int max ) // doesn't have test
{

    int choice = 0;

    cout << ">> ";
    cin >> choice;

    while ( choice < min || choice > max )
    {
        cout << "Choose a number between " << min << " and " << max <<": >> ";
        cin >> choice;
    }

    return choice;
}

int GetRow() // doesn't have test
{
    cout << "Enter row:\t";
    int row = GetUserInput(0, 2);

    return row;
}

int GetColumn() // doesn't have test
{
    cout << "Enter column:\t";
    int column = GetUserInput(0, 2);

    return column;
}

int GetNumber() // doesn't have test
{
    cout << "Enter number:\t";
    int number = GetUserInput(1, 9);

    return number;
}

/* PRE-WRITTEN FUNCTION **************************************/

void DisplayHeader() // done
{
    ClearScreen();  // special function from utilities.hpp
    Header( "Mini-Sudoku" );  // special function from utilities.hpp
}

void SetRandom( int grid[3][3], int randomCount ) // done
{
    vector< Cell > cells = {
        Cell( 0, 0 ), Cell( 0, 1 ), Cell( 0, 2 ),
        Cell( 1, 0 ), Cell( 1, 1 ), Cell( 1, 2 ),
        Cell( 2, 0 ), Cell( 2, 1 ), Cell( 2, 2 )
    };

    if ( randomCount < 0 || randomCount > 8 ) { return; }

    for ( int random = 0; random < randomCount; random++ )
    {
        int v = rand() % cells.size();
        int r = cells[v].r;
        int c = cells[v].c;
        int n = rand() % 9;
        while ( NumberAlreadyUsed( grid, n ) )
        {
            n = rand() % 9;
        }

        grid[r][c] = n;

        cells.erase( cells.begin() + v );
    }
}

void DisplayGrid( int grid[3][3] ) // done
{
    cout << "\t";
    for ( int c = 0; c < 3; c++ )
    {
        cout << "  " << c << " ";
    }
    cout << endl << endl;

    for ( int r = 0; r < 3; r++ )
    {
        cout << r << "\t";
        for ( int c = 0; c < 3; c++ )
        {
            if ( c == 0 ) { cout << "| "; }
            if ( grid[r][c] == 0 )
            {
                cout << "  | ";
            }
            else
            {
                cout << grid[r][c] << " | ";
            }
        }
        if ( r != 2 )
        {
            cout << endl << "\t-------------" << endl;
        }
    }
    cout << endl << endl;
}

#endif
