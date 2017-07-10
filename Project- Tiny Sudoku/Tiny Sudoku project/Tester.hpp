#ifndef _TESTER_HPP
#define _TESTER_HPP

#include <iostream>
#include <string>
using namespace std;

#include "cuTEST/TesterBase.hpp"
#include "cuTEST/Menu.hpp"
#include "cuTEST/StringUtil.hpp"

#include "sudoku_functions.hpp"

class Tester : public TesterBase
{
public:
	Tester()
	{
		AddTest(TestListItem("PlaceNumberInCell()",
            bind(&Tester::Test_PlaceNumberInCell, this)));

		AddTest(TestListItem("CellIsTaken()",
            bind(&Tester::Test_CellIsTaken, this)));

		AddTest(TestListItem("NumberAlreadyUsed()",
            bind(&Tester::Test_NumberAlreadyUsed, this)));

		AddTest(TestListItem("AllCellsTaken()",
            bind(&Tester::Test_AllCellsTaken, this)));

		AddTest(TestListItem("ResetGrid()",
            bind(&Tester::Test_ResetGrid, this)));
	}

	virtual ~Tester()
	{
	}

private:
	int Test_PlaceNumberInCell();
	int Test_CellIsTaken();
	int Test_NumberAlreadyUsed();
	int Test_AllCellsTaken();
	int Test_ResetGrid();
};

int Tester::Test_PlaceNumberInCell()
{
    InitTest( "PlaceNumberInCell", { } );

    int grid[3][3] = {
        { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }
    };
    int row, column, number;

    StartTest( "Check to make sure PlaceNumberInCell() updates the grid properly" );

    bool fail = false;
    for ( row = 0; row < 3; row++ )
    {
        for ( column = 0; column < 3; column++ )
        {
            for ( number = 1; number <= 9; number++ )
            {
                PlaceNumberInCell( grid, row, column, number );
                if ( grid[row][column] != number )
                {
                    TestFail();
                    ReportFailure( "PlaceNumberInCell_Test1", "Tried to place number " + StringUtil::ToString( number ) + " into grid at row " + StringUtil::ToString( row ) + " column " + StringUtil::ToString( column ) + ". Instead, the number " + StringUtil::ToString( grid[row][column] ) + " is in that location." );
                    fail = true;
                }
            }
        }
    }
    if ( !fail )
    {
        TestPass();
        ReportPass();
    }


    DisplayScore();
    return TestResult();
}

int Tester::Test_CellIsTaken()
{
    InitTest( "CellIsTaken", { } );

    int grid[3][3] = {
        { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }
    };
    int row, column;

    StartTest( "Check to see if CellIsTaken() returns false for all cells in an empty grid" );

    bool fail = false;
    for ( row = 0; row < 3; row++ )
    {
        for ( column = 0; column < 3; column++ )
        {
            if ( CellIsTaken( grid, row, column ) )
            {
                TestFail();
                ReportFailure( "CellIsTaken_Test1", "With empty grid, checked row " + StringUtil::ToString( row ) + " column " + StringUtil::ToString( column ) + ", CellIsTaken() should return FALSE but returned TRUE." );
                fail = true;
            }
        }
    }
    if ( !fail )
    {
        TestPass();
        ReportPass();
    }


    int grid2[3][3] = {
        { 1, 2, 3 }, { 7, 8, 9 }, { 4, 5, 6 }
    };
    StartTest( "Check to see if CellIsTaken() returns true for a full grid" );

    fail = false;
    for ( row = 0; row < 3; row++ )
    {
        for ( column = 0; column < 3; column++ )
        {
            if ( CellIsTaken( grid2, row, column ) == false )
            {
                TestFail();
                ReportFailure( "CellIsTaken_Test2", "With full grid, checked row " + StringUtil::ToString( row ) + " column " + StringUtil::ToString( column ) + ", CellIsTaken() should return TRUE but returned FALSE." );
                fail = true;
            }
        }
    }
    if ( !fail )
    {
        TestPass();
        ReportPass();
    }


    int grid3[3][3] = {
        { 1, 2, 0 }, { 7, 0, 9 }, { 0, 5, 6 }
    };
    StartTest( "Check to see if CellIsTaken() returns true or false correctly on partially-filled grid" );

    fail = false;
    for ( row = 0; row < 3; row++ )
    {
        for ( column = 0; column < 3; column++ )
        {
            if ( CellIsTaken( grid3, row, column ) == true && grid3[row][column] == 0 )
            {
                TestFail();
                ReportFailure( "CellIsTaken_Test3", "Checked row " + StringUtil::ToString( row ) + " column " + StringUtil::ToString( column ) + ", this cell is empty, so CellIsTaken() should return FALSE but returned TRUE" );
                fail = true;
            }
            else if ( CellIsTaken( grid3, row, column ) == false && grid3[row][column] != 0 )
            {
                TestFail();
                ReportFailure( "CellIsTaken_Test3", "Checked row " + StringUtil::ToString( row ) + " column " + StringUtil::ToString( column ) + ", this cell is full, so CellIsTaken() should return TRUE but returned FALSE" );
                fail = true;
            }
        }
    }
    if ( !fail )
    {
        TestPass();
        ReportPass();
    }


    DisplayScore();
    return TestResult();
}

int Tester::Test_NumberAlreadyUsed()
{
    InitTest( "NumberAlreadyUsed", { } );

    int grid[3][3] = {
        { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }
    };

    int testNumbers[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    StartTest( "Test to make sure FALSE is returned for all numbers with an empty grid" ); //Added this

    bool fail = false;
    for ( int i = 0; i < 9; i++ )
    {
        if ( NumberAlreadyUsed( grid, testNumbers[i] ) == true )
        {
            TestFail();
            ReportFailure( "NumberAlreadyUsed_Test1", "Using empty grid, NumberAlreadyUsed() returned TRUE for number " + StringUtil::ToString( testNumbers[i] ) );
            fail = true;
        }
    }
    if ( fail == false )
    {
        TestPass();
        ReportPass();
    }

    StartTest( "Test if function returns TRUE if an element matches the input, and FALSE if it doesn't" ); //Added this line -Philip
    fail = false;
    for ( int i = 0; i < 9; i++ )
    {
        grid[1][1] = testNumbers[i];

        if ( NumberAlreadyUsed( grid, testNumbers[i] ) == false )
        {
            TestFail();
            ReportFailure( "NumberAlreadyUsed_Test2", "Added " + StringUtil::ToString( testNumbers[i] ) + " to grid, but NumberAlreadyUsed() returns FALSE, expected TRUE." );
            fail = true;
        }
        else if ( i < 8 && NumberAlreadyUsed( grid, testNumbers[i+1] ) == true )
        {
            TestFail();
            ReportFailure( "NumberAlreadyUsed_Test2", "Added " + StringUtil::ToString( testNumbers[i] ) + " to grid, but checking for " + StringUtil::ToString( testNumbers[i+1] ) + " returns TRUE, expected FALSE" );
            fail = true;
        }
    }
    if ( fail == false )
    {
        TestPass();
        ReportPass();
    }


    int grid2[3][3] = {
        { 7, 8, 9 }, { 4, 5, 6 }, { 1, 2, 3 }
    };

    StartTest( "Test if FALSE is returned for all inputs in a valid full grid" ); //Added this line -Philip
    fail = false;
    for ( int i = 0; i < 9; i++ )
    {
        if ( NumberAlreadyUsed( grid2, testNumbers[i] ) == false )
        {
            TestFail();
            ReportFailure( "NumberAlreadyUsed_Test3", "In a full grid, checked for " + StringUtil::ToString( testNumbers[i] ) +" but returns FALSE, expected TRUE" );
            fail = true;
        }
    }
    if ( fail == false )
    {
        TestPass();
        ReportPass();
    }

    DisplayScore();
    return TestResult();
}

int Tester::Test_AllCellsTaken()
{
    InitTest( "AllCellsTaken", { } );

    int grid[3][3] = {
        { 2, 2, 2 }, { 3, 3, 3 }, { 4, 4, 4 }
    };

    StartTest( "Check that TRUE is returned if ALL cells are taken." );

    if ( AllCellsTaken( grid ) == false )
    {
        TestFail();
        ReportFailure( "AllCellsTaken_Test1", "The grid is full, but AllCellsTaken() returned FALSE!" );
    }
    else
    {
        TestPass();
        ReportPass();
    }



    StartTest( "Check that FALSE is returned if there EXISTS at least one cell that is not taken." );
    AdditionalDescription( "For a cell to be considered \"empty\", it must be assigned the value of 0." );

    int grid2[3][3] = {
        { 2, 2, 2 }, { 3, 3, 3 }, { 4, 0, 4 }
    };

    if ( AllCellsTaken( grid2 ) == true )
    {
        TestFail();
        ReportFailure( "AllCellsTaken_Test2", "The grid is not full, there is one cell that is empty, but AllCellsTaken() returned TRUE!" );
    }
    else
    {
        TestPass();
        ReportPass();
    }



    StartTest( "Check that FALSE is returned if the entire grid is empty." );
    AdditionalDescription( "For a cell to be considered \"empty\", it must be assigned the value of 0." );

    int grid3[3][3] = {
        { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }
    };

    if ( AllCellsTaken( grid3 ) == true )
    {
        TestFail();
        ReportFailure( "AllCellsTaken_Test2", "The grid is completely empty, but AllCellsTaken() returned TRUE!" );
    }
    else
    {
        TestPass();
        ReportPass();
    }




    DisplayScore();
    return TestResult();
}

int Tester::Test_ResetGrid()
{
    InitTest( "ResetGrid", { } );

    int grid[3][3] = {
        { 2, 2, 2 }, { 3, 3, 3 }, { 4, 4, 4 }
    };

    StartTest( "Check that all cells are 0" );
    AdditionalDescription( "The grid is 3x3, so there are 9 cells." );
    AdditionalDescription( "After the ResetGrid() function is called on the grid," );
    AdditionalDescription( "all cells of the grid should be set to 0." );
    ResetGrid( grid );

    bool fail = false;
    for ( int y = 0; y < 3; y++ )
    {
        for ( int x = 0; x < 3; x++ )
        {
            if ( grid[x][y] != 0 )
            {
                TestFail();
                ReportFailure( "ResetGrid_Test1", "cell " + StringUtil::ToString( x ) + ", " + StringUtil::ToString( y ) + " is not reset to 0" );
                fail = true;
            }
        }
    }

    if ( !fail )
    {
        TestPass();
        ReportPass();
    }

    DisplayScore();
    return TestResult();
}

#endif
