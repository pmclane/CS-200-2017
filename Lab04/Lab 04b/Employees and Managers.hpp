#include <iostream>
#include <string>
#include <cstdlib>      // for srand and rand
#include <ctime>        // for time
using namespace std;

const int MANAGER_COUNT = 2;
const int EMPLOYEE_COUNT = 5;

void AssignManagers( string managerNames[ MANAGER_COUNT ], string * employeeManagers[ EMPLOYEE_COUNT ] )
{
    for (int i = 0; i < EMPLOYEE_COUNT; i++)
    {
        int index = rand() % MANAGER_COUNT;
        employeeManagers[i] = &managerNames[index];
    }
}

void DisplayEmployees( string employeeNames[ EMPLOYEE_COUNT ], string * employeeManagers[ EMPLOYEE_COUNT ] )
{
    for (int i = 0; i < EMPLOYEE_COUNT; i++)
    {
        cout << "Employee #" << i << ": " << employeeNames[i] << "\t Manager: " << *employeeManagers[i] << endl;
    }
}

void EmployeesAndManagers()
{
    //Managers
    string managerNames[MANAGER_COUNT];
    managerNames[0] = "Celeste Hanigan";
    managerNames[1] = "Folami Nicolai";

    //Employees
    string employeeNames[EMPLOYEE_COUNT];
    employeeNames[0] = "Hanne Mosconi";
    employeeNames[1] = "Yuuki Van Peij";
    employeeNames[2] = "Mitra Stenberg";
    employeeNames[3] = "Keanu Coemans";
    employeeNames[4] = "Wangchuk Jaso";

    string* employeeManagers[EMPLOYEE_COUNT];

    AssignManagers(managerNames, employeeManagers);

    DisplayEmployees(employeeNames, employeeManagers);

}
