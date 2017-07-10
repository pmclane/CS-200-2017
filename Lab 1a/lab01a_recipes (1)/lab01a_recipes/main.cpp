#include <iostream>
using namespace std;

//Function to display ingredients
void sugarCookieRecipe(float baking_powder, float baking_soda, float sugar, float butter, float eggs)
{

    cout << baking_soda << " tbsp\tbaking soda" << endl;
    cout << baking_powder << " tsp\tbaking powder" << endl;
    cout << sugar << " cp\twhite sugar" << endl;
    cout << butter << " cp\tbutter" << endl;
    cout << eggs << " \tegg";

    if ( eggs != 1)
    {
        cout << "s";
    }
    cout << endl << endl;
}
int main()
{
    char doExit = 'n';
    while (doExit != 'y' && doExit != 'Y')
    {
        float baking_powder = 0.5;
        float baking_soda = 1;
        float batches;
        float sugar = 1.5;
        float butter = 1;
        float eggs = 2;

        cout << "Sugar Cookie Recipe" << endl;
        sugarCookieRecipe( baking_powder, baking_soda, sugar, butter, eggs );

        cout << "How many batches would you like to make?" << endl;
        cin >> batches;
        baking_powder *=  batches;
        baking_soda *= batches;
        sugar *= batches;
        butter *= batches;
        eggs *= batches;

        //Output ingredients for requested batches
        cout << endl << "All right. For " << batches << " batch";
        if ( batches != 1)
        {
            cout << "es";
        }

        cout << " you'll need the following:" << endl << endl;
        sugarCookieRecipe( baking_powder, baking_soda, sugar, butter, eggs );

        //Ask user if they want to exit.
        cout << endl << endl << "Do you want to exit? (y/n)";
        cin >> doExit;

    }
        return 0;
}

