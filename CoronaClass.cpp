#include "CoronaClass.h"

CoronaClass::CoronaClass() : HospitalName("NULL"),DocArr(nullptr),numOfDoctors(1),NurArr(nullptr),numOfNurses(1),
PatArr(nullptr),numOfPatients(1) // def ctor
{


}

CoronaClass::CoronaClass(string hname, Doctor * D, int Dnum, Nurse * N, int Nnum, Patient * P, int Pnum) : HospitalName(hname)
{ // ctor with arguments
	if (D != NULL)
	{
		this->numOfDoctors = Dnum;
		this->DocArr = new Doctor*[numOfDoctors];
		for (int i = 0; i < numOfDoctors; i++)
			DocArr[i] = (&D)[i];

	}

	else
	{
		this->DocArr = nullptr;
		this->numOfDoctors = 0;
	}

	if (N != NULL)
	{
		this->numOfNurses = Nnum;
		this->NurArr = new Nurse*[numOfNurses];
		for (int i = 0; i < numOfNurses; i++)
			this->NurArr[i] = &N[i];
	}

	else
	{
		this->NurArr = nullptr;
		this->numOfNurses = 0;
	}

	if (P != NULL)
	{
		this->numOfPatients = Pnum;
		this->PatArr = new Patient*[numOfPatients];
		for (int i = 0; i < numOfPatients; i++)
			PatArr[i] = &P[i];
	}

	else
	{
		this->PatArr = nullptr;
		this->numOfPatients = 0;
	}
}

CoronaClass::~CoronaClass() //default distractur
{
	for (int i = 0; i < this->numOfDoctors; i++)
		delete this->DocArr[i];

		delete [] this ->DocArr;

		for (int i = 0; i < this->numOfNurses; i++)
			delete this->NurArr[i];

		delete[] this ->NurArr;

		for (int i = 0; i < this->numOfPatients; i++)
			delete this->PatArr[i];

		delete[] this ->PatArr;
}

void CoronaClass::addDoctor(Doctor * Doc) 
{
	if (Doc != NULL)
	{
		Doctor * temp;
		temp = new Doctor[this->numOfDoctors];
		for (int i = 0; i < this->numOfDoctors; i++)
			temp[i] = (*DocArr)[i];

		for (int i = 0; i < this->numOfDoctors; i++)
			delete DocArr[i];

		delete[] this->DocArr;

		numOfDoctors += 1;
		DocArr = new Doctor*[this->numOfDoctors];

		for (int i = 0; i <this->numOfDoctors; i++)
		{
			if (i == this->numOfDoctors - 1)
				this->DocArr[i] = Doc;
			else
				(*DocArr)[i] = temp[i];
		}

		delete[] temp;

	}

	else
	{
		cout << "Invaild input!" << endl;
		exit(1);
	}
}

void CoronaClass::addNurse(Nurse * Nur)
{
	if (Nur != NULL)
	{
		Nurse * temp;
		temp = new Nurse[this->numOfNurses];
		for (int i = 0; i < this->numOfNurses; i++)
			temp[i] = (*NurArr)[i];

		for (int i = 0; i < this->numOfNurses; i++)
			delete NurArr[i];
		
		delete[] this->NurArr;

		this->numOfNurses += 1;
		NurArr = new Nurse*[this->numOfNurses];

		for (int i = 0; i < numOfNurses; i++)
		{
			if (i == numOfNurses - 1)
				NurArr[i] = Nur;
			else
				(*NurArr)[i] = (temp)[i];
		}

		

		delete[] temp;

	}

	else
	{
		cout << "Invaild input!" << endl;
		exit(1);
	}
}

void CoronaClass::addPatient(Patient * Pat) 
{
	if (Pat == NULL || (!(this->numOfDoctors >= 1 && this->numOfNurses >= 2)))
	{
		 if (!(this->numOfDoctors >= 1 && this->numOfNurses >= 2))
		{
			cout << "Not enough doctors / nurses in the department! " << endl;
			exit(1);
		}
		 else
		 {
			 cout << "Invaild input!" << endl;
			 exit(1);
		 }
	}

	else
	{
		Patient * temp;
		temp = new Patient[this->numOfPatients];
		for (int i = 0; i < this->numOfPatients; i++)
			temp[i] = (*PatArr)[i];

		for (int i = 0; i < this->numOfPatients; i++)
			delete PatArr[i];

		delete[] this->PatArr;

		this->numOfPatients += 1;
		PatArr = new Patient*[this->numOfPatients];

		for (int i = 0; i < this->numOfPatients; i++)
		{
			if (i == this->numOfPatients - 1)
				PatArr[i] = Pat;
			else
				(*PatArr)[i] = temp[i];
		}

		delete[] temp;
	}
}



void CoronaClass::printDocArr()const
{
	for (int i = 0; i < this->numOfDoctors; i++)
	{
		(*DocArr)[i].printEmployee(); // use virtual func
	}
}

void CoronaClass::printNurArr()const
{
	for (int i = 0; i < this->numOfNurses; i++)
	{
		(*NurArr)[i].printEmployee(); // use virtual func
	}
}

void CoronaClass::printPatArr()const
{
	for (int i = 0; i < this->numOfPatients; i++)
	{
		(*PatArr)[i].personPrint(); // use virtual func
	}
}



void CoronaClass::printCoronaClass()const
{
	cout << "Corona class data: " << endl;
	cout << "Name of hospital: " << this->HospitalName << endl;
	cout << "-----Docotrs data -----" << endl;
	cout << "Number of doctors: " << this->numOfDoctors << endl;

	for (int i = 0; i < this->numOfDoctors; i++)
		(*DocArr)[i].printEmployee();

	cout << "\n-----Nurses data -----" << endl;
	cout << "Number of Nurses: " << this->numOfNurses << endl;

	for (int i = 0; i < this->numOfNurses; i++)
		(*NurArr)[i].printEmployee();

	cout << "\n-----Patients data -----" << endl;
	cout << "Number of Patients: " << this->numOfPatients << endl;

	for (int i = 0; i < this->numOfPatients; i++)
		(*PatArr)[i].personPrint();



}