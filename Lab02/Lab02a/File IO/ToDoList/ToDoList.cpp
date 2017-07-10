#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string toDoItem;
    int toDoCounter = 1;

    ofstream file;
    file.open( "todo.txt" );

    file << "to do list" << endl;   // write to text file
    cout << "to do list" << endl;   // write to screen

    while ( true )
    {
        // Get item in to do list
        cout << endl;
        cout << "Next item to do, or QUIT to stop." << endl;
        cout << ">> ";
        getline( cin, toDoItem );

        if ( toDoItem == "QUIT" ) { break; }


        file << toDoCounter << ". " << toDoItem << endl; //Output to file


        toDoCounter++;
    }

    file.close();

    return 0;
}

