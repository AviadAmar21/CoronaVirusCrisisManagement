#include "CoronaClass.h"
#define ADD_NURSE 1
#define ADD_DOCTOR 2
#define ADD_DEPARTMENT 3
#define PRINT_DEPARTMENT_DETAILS 4
#define PRINT_DOCTORS_DETAILS 5
#define PRINT_SALARY_BY_ID 6
#define ADD_PATIENT 7
#define ADD_CORONA_TEST_TO_PATIENT_ID 8
#define RELEASING_PATIENTS 9
#define PRINT_EXCELLENCE_WORKER 10
#define PRINT_NURSE_DETAILS_WITH_SMALLEST_SALARY 11
#define EXIT 12
#define N 5




class CoronaVirusCrisisManagement
{
private:

	Patient ** PatDArr;
	int pArrNum;
	CoronaClass  **ClassDArr;
	int cClassArrNum;
	Employee ** empDArr;
	int empArrNum;

public:
	void Menu();
	void printOptions()const;
	void AddNurse();
	void AddDoctor();
	void AddDepartment();
	void PrintDepartmentDetails()const;
	void PrintDoctorsDetails()const;
	void PrintSalary()const;
	void AddPatient();
	void AddCoronaTestToPatientById();
	void Releasing();
	void PrintExcellenceWorker()const;
	void PrintNurseWithSmallestSalary()const;
	
	CoronaVirusCrisisManagement();
	~CoronaVirusCrisisManagement();

};
#pragma once
