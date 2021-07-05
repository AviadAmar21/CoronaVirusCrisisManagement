#include "Doctor.h"

Doctor::Doctor() : Employee() ,DepName("NULL"),prof(false),positive(0) // dctor
{
	

}

Doctor::Doctor(string name, string lname, string num, int mis,string dname, bool pro, int pos) : Employee(name, lname, num,mis),
DepName(dname), prof(pro), positive(pos) {} // ctor with arguments


Doctor& Doctor:: operator = (const Doctor& Doc2)
{
	this->firstName = Doc2.firstName;
	this->lastName = Doc2.lastName;
	this->id = Doc2.id;
	this->years = Doc2.years;
	this->DepName = Doc2.DepName;
	this->positive = Doc2.positive;
	this->prof = Doc2.prof;

	return *this;
}

int Doctor::getSalary() const //  virtual function
{
	if (prof)
		return BASIS + PROFES + (OP1 * this->getYears()) + (OP * this->positive);
	else
		return BASIS + (OP1 * this->getYears()) + (OP * this->positive);
}

bool Doctor::isOutstanding() const //  virtual function
{
	if (positive > 10)
		return true;

	return false;
}

void Doctor::printEmployee() const
{
	cout << "Doctor data: " << endl;
	cout << "Depeartmnent name: " << DepName << endl;
	cout << "Salary: " << this->getSalary() << endl;
	if (prof)
		cout << "The employee is Proffessor!" << endl;
	else
		cout << "The employee is NOT Proffessor!" << endl;

	Employee::printEmployee();


}