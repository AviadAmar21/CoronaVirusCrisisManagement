#include "Employee.h"

Employee::Employee() : Person(),years(NULL) // dctor
{
	
}

Employee::Employee(string name, string lname, string num,int mis) : Person(name, lname, num),years(mis) // ctor with arguments
{
	
}

Employee :: ~Employee() {}



void Employee::printEmployee() const
{
	cout << "Employee data: " << endl;
	cout << "Years of seniority: " << years << endl;
	cout << "Salary: " << getSalary() << endl;
	Person::personPrint();

}