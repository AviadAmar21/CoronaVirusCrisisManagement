#include "Employee.h"
#define OP1 200
#define PROFES 2000


class Doctor : public Employee
{
protected:
	string DepName;
	bool prof;
	int positive;

public:
	Doctor();
	Doctor(string name, string lname, string num,int mis, string dname, bool pro, int pos);
	~Doctor() {}
	Doctor & operator = (const Doctor & Doc2);
	int getSalary() const;
	bool isOutstanding() const;
	void printEmployee()const;
	string getDepName()const { return DepName; }
	bool getProf() const { return prof; }
	int getPositive() const { return positive; }
	void setDepName(string name) { this->DepName = name; }
	void setProf(bool pro) { this->prof = pro; }
	void setPositive(int pos) { this->positive = pos; }
	void TrueProf() { this->prof = true; }
	void FalseProf() { this->prof = false; }



};






#pragma once
