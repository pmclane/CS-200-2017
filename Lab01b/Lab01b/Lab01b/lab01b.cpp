#include <iostream>
#include <string>
using namespace std;

int main()
{
    char do_exit = 'n';

    while ( do_exit != 'y' && do_exit != 'Y')
    {
        //Hometown code
        string hometown, name;

        cout << "What is your home town?" << endl;
        cin >> hometown;

        if ( hometown.size() > 6 )
        {
            cout << "That's a long name!" << endl;
        }

        cout << endl << "What's your name?" << endl;
        cin >> name;
        cout << "Hello, " << name << " from " << hometown << "!" << endl;

        //Pass/Fail code
        float score, max_score;

        cout << endl << endl << "What was your score? ";
        cin >> score;
        cout << "What was the total possible points? ";
        cin >> max_score;

        score = (score/max_score)*100;

        cout << "Score:\t" << score << "%";

        if ( score < 70 )
        {
            cout << "\tFail" << endl;
        }
        else
        {
            cout << "\tPass" << endl;
        }

        //Battery charge code
        float charge;
        cout << endl << endl << "What is your current battery charge? %";
        cin >> charge;

        if ( charge <= 0 )
        {
            cout << "[DEAD]" << endl;
        }
        else if ( charge < 37.5 )
        {
            cout << "[*   ]" << endl;
        }
        else if ( charge < 62.5 )
        {
            cout << "[**  ]" << endl;
        }
        else if ( charge < 87.5 )
        {
            cout << "[*** ]" << endl;
        }
        else
        {
            cout << "[****]" << endl;
        }

        //Input Validation code
        int fruit_choice;

        cout << endl << endl << "Which of the following is your favorite fruit?" << endl;
        cout << "1. Apple" << endl;
        cout << "2. Banana" << endl;
        cout << "3. Pear" << endl;
        cout << "4. Strawberry" << endl;
        cin >> fruit_choice;

        cout << endl << "You selection: " << fruit_choice << endl;

        if ( fruit_choice != 1 && fruit_choice != 2 && fruit_choice != 3 && fruit_choice != 4)
        {
            cout << "Invalid Choice!" << endl;
        }
        else
        {
            cout << "Good choice!" << endl;
        }

        //Switch Statement code
        float a, b;
        int choice;

        cout << "Choose a number: ";
        cin >> a;
        cout << "Choose a second number: ";
        cin >> b;

        cout << "What would you like to do with these numbers?" << endl;
        cout << "1. Add" << endl;
        cout << "2. Subtract" << endl;
        cout << "3. Multiply" << endl;
        cout << "4. Divide" << endl;
        cin >> choice;

        switch( choice )
        {
            case 1:
                cout << a + b;
                break;

            case 2 :
                cout << a - b;
                break;

            case 3 :
                cout << a * b;
                break;

            case 4 :
                cout << a / b;
                break;

            default :
                cout << "Invalid choice.";

        }
        cout << endl << endl << "Would you like to exit? (y/n) ";
        cin >> do_exit;
    }

    return 0;
}
