#include <iostream>
#include <string>
using namespace std;

void Program1()
{
    string names[5];
    names[0] = "Xia";
    names[1] = "Shang";
    names[2] = "Zhou";
    names[3] = "Qin";
    names[4] = "Han";

    //This seemed like the natural (if inelegant) solution to outputting names.
    for (int current = 0; current < 5; current++)
    {
        cout << names[current] << endl;
    }


    cout << endl << endl; //Create separation from option list in output.
}

void Program2()
{
    string names[5];
    names[0] = "Xia";
    names[1] = "Shang";
    names[2] = "Zhou";
    names[3] = "Qin";
    names[4] = "Han";
    int index = 0;
    int arraySize = 5;

    for (index = 0; index < arraySize; index++)
    {
        cout << names[index] << endl;
    }

    cout << endl << endl;

}

void Program3()
{
    string items[3];
    float prices[3];
    int arraySize = 3;
    int itemCount = 0;

    while (itemCount < arraySize)
    {
        cout << "Enter item name: ";
        cin >> items[itemCount];
        cout << "Enter price: ";
        cin >> prices[itemCount];

        itemCount++;
    }

    int counter = 0;

    cout << endl;

    while (counter < itemCount)
    {
        cout << "Item #" << counter << ": " << items[counter] << "\t $" << prices[counter] << endl;

        counter++;
    }

    cout << endl << endl;

}

void Program4()
{
    string letters[5] = { "A", "B", "C", "D", "E" };

    for (int count = 0; count < 5; count++)
    {
        cout << letters[count] << endl;
    }

    cout << endl << endl;
}

void Program5()
{
    string items[3];
    float prices[3];
    int arraySize = 3;

    for (int counter = 0; counter < arraySize; counter++)
    {
        cout << "Enter item name: ";
        cin >> items[counter];
        cout << "Enter price: ";
        cin >> prices[counter];
    }

    cout << endl;

    for (int counter = 0; counter < arraySize; counter++)
    {
        cout << "Item #" << counter << ": " << items[counter] << "\t $" << prices[counter] << endl;
    }

    cout << endl << endl;

}
    void Program6()
{
	string cities[20];
	int arraySize = 20;
	cities[0] = "Lee's Summit";
	cities[1] = "Raytown";
	cities[2] = "Independence";
	cities[3] = "Belton";
	int itemCount = 4;

	for (int counter = 0; counter < itemCount; counter++)
    {
        cout << cities[counter] << endl;
    }

    cout << endl << endl;
}

int main()
{
    bool done = false;

    while ( !done )
    {
        int choice;
        cout << "0. QUIT" << endl;
        cout << "1. Program 1" << endl;
        cout << "2. Program 2" << endl;
        cout << "3. Program 3" << endl;
        cout << "4. Program 4" << endl;
        cout << "5. Program 5" << endl;
        cout << "6. Program 6" << endl;
        cout << endl << ">> ";
        cin >> choice;

        switch( choice )
        {
            case 0: done = true; break;
            case 1: Program1(); break;
            case 2: Program2(); break;
            case 3: Program3(); break;
            case 4: Program4(); break;
            case 5: Program5(); break;
            case 6: Program6(); break;
        }
    }

	return 0;
}
