#ifndef _SCHOLARSHIP_HPP
#define _SCHOLARSHIP_HPP

#include <string>
using namespace std;

#include "Student.hpp"

struct Scholarship
{
public:     // accessible outside the struct
	void Display()
	{
		cout << "Scholarship: " << name << ", Value: $" << amount << endl
			<< "Students:" << endl;
		for (int i = 0; i < 3; i++)
		{
			cout << "\t" << (i + 1) << " "
				<< (*studentPtrList[i]).name << "\t"
				<< (*studentPtrList[i]).gpa << endl;
		}
	}

	void Setup(string newName, float newAmount, Student* student1, Student* student2, Student* student3 )
	{
		name = newName;
		amount = newAmount;
		studentPtrList[0] = student1;
		studentPtrList[1] = student2;
		studentPtrList[2] = student3;
	}



private:    // only accessible within the struct
	string name;
	float amount;
	Student* studentPtrList[3];

};

#endif
