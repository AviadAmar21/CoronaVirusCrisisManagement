#include "Person.h"
#include "Employee.h"
#include "Doctor.h"
#include "Nurse.h"
#include "Patient.h"

class CoronaClass {
protected:

	string HospitalName;
	Doctor ** DocArr;
	int numOfDoctors;
	Nurse ** NurArr;
	int numOfNurses;
	Patient ** PatArr;
	int numOfPatients;

public:
	CoronaClass();
	CoronaClass(string hname, Doctor * D, int Dnum, Nurse * N, int Nnum, Patient * P, int Pnum);
	~CoronaClass();
	void addDoctor(Doctor * Doc);
	void addNurse(Nurse * Nur);
	void addPatient(Patient* Pat);
	void printCoronaClass()const;
	void printDocArr()const;
	void printNurArr()const;
	void printPatArr()const;
	string getHospitalName () { return this -> HospitalName; }
	void setHospitalName(string hos) { this->HospitalName = hos; }
	int getPatientNum() const { return numOfPatients; }
	Patient ** getPatArr() { return PatArr; }




};
#pragma once
