#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int menuChoice;

    int pizzaVotes = 0;
    int samosaVotes = 0;
    int sushiVotes = 0;
    int tacoVotes = 0;

    while ( true )
    {
        cout << endl << endl
            << "What is the best food?" << endl << endl;
        cout << "1. Vote for PIZZA" << endl;
        cout << "2. Vote for SAMOSA" << endl;
        cout << "3. Vote for SUSHI" << endl;
        cout << "4. Vote for TACO" << endl;
        cout << "5. Quit and tally votes" << endl;

        cin >> menuChoice;

        if ( menuChoice == 5 )
        {
            break;
        }

        // TODO: Depending on what the user voted for,
        // add +1 to the votes variable.
        switch ( menuChoice )
        {
        case 1:
            pizzaVotes++;
            break;

        case 2:
            samosaVotes++;
            break;

        case 3:
            sushiVotes++;
            break;

        case 4:
            tacoVotes++;
            break;

        default:
            cout << "Invalid Entry";
            break;
        }

    }

    // TODO: Output tallies to output file
    ofstream voteCount;
    voteCount.open( "Vote Results.txt" );
    voteCount << "Pizza: " << pizzaVotes << endl
                << "Samosa: " << samosaVotes << endl
                << "Sushi: " << sushiVotes << endl
                << "Taco: " << tacoVotes << endl;

    voteCount.close();
    return 0;
}
