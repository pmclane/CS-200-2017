#include <iostream>
#include <string>
using namespace std;

#include "Student.hpp"
#include "Fraction.hpp"
#include "Scholarship.hpp"

void Program1()
{
	Student newStudent;
	newStudent.degree = "Submarine Reed Integration";
	newStudent.gpa = 3.7;
	newStudent.name = "Ade Groos";

	cout << "Student Name:\t" << newStudent.name << endl
		<< "Degree: \t" << newStudent.degree << endl
		<< "GPA: \t\t" << newStudent.gpa << endl;

}

void OutputOperation(string operation, Fraction a, Fraction b) //I was going to put this in Fraction.hpp, but figured the extra functionality would make assessment harder.
{
	cout << operation;
	
	if (operation == "Difference")
	{
		cout << " between ";
	}
	else
	{
		cout << " of ";
	}
	a.Display();
	cout << " and ";
	b.Display();
	cout << " is ";

}

void Program2()
{
	Fraction frac1, frac2;
	
	frac1.Setup(2, 3);
	frac2.Setup(3, 4);
	
	Fraction sum, difference, product, quotient;

	sum = frac1.Add(frac2);
	difference = frac1.Subtract(frac2);
	product = frac1.Multiply(frac2);
	quotient = frac1.Divide(frac2);


	OutputOperation("Sum", frac1, frac2);
	sum.Display();
	cout << endl;

	OutputOperation("Difference", frac1, frac2);
	difference.Display();
	cout << endl;
	
	OutputOperation("Product", frac1, frac2);
	product.Display();
	cout << endl;

	OutputOperation("Quotient", frac1, frac2);
	quotient.Display();
	cout << endl;

}

void Program3()
{
	Student students[9]; //Names (besides Eunhye Lee) generated using http://www.behindthename.com/random/
	students[0].degree = "Applied Physics";
	students[0].gpa = 3.41;
	students[0].name = "Nsia Lynton";

	students[1].degree = "Psychology";
	students[1].gpa = 2.84;
	students[1].name = "Willy Burns";


	students[2].degree = "Fine Arts";
	students[2].gpa = 3.92;
	students[2].name = "Eunhye Lee";
	
	//Degrees generated using http://www.mithrilandmages.com/utilities/Majors.php
	students[3].degree = "Economics - Feminist Economics";
	students[3].gpa = 3.41;
	students[3].name = "Simcha Travers";

	students[4].degree = "Geography - Physical Geography : Coastal Geography";
	students[4].gpa = 2.21;
	students[4].name = "Willy Burns";

	students[5].degree = "Space Sciences - Astrophysics : Gravitational Astronomy";
	students[5].gpa = 4.0;
	students[5].name = "Gomer Abraham";
	
	students[6].degree = "Physics - Statistical Mechanics";
	students[6].gpa = 2.41;
	students[6].name = "Ghufran Hamasaki";

	students[7].degree = "Journalism, Media Studies And Communication - Media Studies (Mass Media) : Radio";
	students[7].gpa = 3.64;
	students[7].name = "Haris Winterbottom";

	students[8].degree = "Religion - Abrahamic Religions : Islam / Islamic Studies";
	students[8].gpa = 3.97;
	students[8].name = "Chao Maddox";

	Scholarship scholarships[3];
	scholarships[0].Setup("small", 100, &students[0], &students[1], &students[2]);
	scholarships[1].Setup("medium", 1000, &students[3], &students[4], &students[5]);
	scholarships[2].Setup("large", 10000, &students[6], &students[7], &students[8]);

	for (int i = 0; i < 3; i++)
	{
		scholarships[i].Display();
		cout << endl;
	}

}

int main()
{
	while (true)
	{
		cout << "1. Program 1" << endl;
		cout << "2. Program 2" << endl;
		cout << "3. Program 3" << endl;
		cout << "Run which lab? ";
		int choice;
		cin >> choice;

		cout << endl << endl;

		switch (choice)
		{
		case 1:     Program1();     break;
		case 2:     Program2();     break;
		case 3:     Program3();     break;
		default:	cout << "Invalid Input" << endl; break; //Added to prevent madness when I hit something besides 1-3.
		}

		cout << endl << endl;
	}

	return 0;
}