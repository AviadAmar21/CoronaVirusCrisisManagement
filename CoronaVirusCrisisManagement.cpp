#include "CoronaVirusCrisisManagement.h"
#define START 3
#define MIN 999999999

CoronaVirusCrisisManagement::CoronaVirusCrisisManagement() //dctor
{
	this->PatDArr = new Patient*[1]; 
	PatDArr[0] = new Patient("Empty", "Empty", "Empty", "Empty", 0, 0);

	this->empArrNum = START;
	this -> empDArr= new Employee*[START];

	

	Doctor** DocTemp = new Doctor*[1];
	DocTemp[0] = new Doctor("Aviad","Amar","312581986",6,"Soroka",true,8);



	Nurse ** NurTemp = new Nurse*[START - 1];
	NurTemp[0] = new Nurse("Nurse1", "Nurse1","123456789",4,"Soroka",6);
	NurTemp[1] = new Nurse("Nurse2", "Nurse2", "123456789", 4, "Soroka", 2);

	empDArr[0] = DocTemp[0];
	empDArr[1] = NurTemp[0];
	empDArr[2] = NurTemp[1];

	

	ClassDArr = new CoronaClass*[START - (START - 1)];
	ClassDArr[0] = new CoronaClass("Soroka", *DocTemp, 1, *NurTemp, 2, *PatDArr, 1);


}

CoronaVirusCrisisManagement::~CoronaVirusCrisisManagement() //ctor with arguments
{
	for (int i = 0; i < this->pArrNum; i++)
		delete this->PatDArr[i];

	delete this->PatDArr;

	for (int i = 0; i < this->empArrNum; i++)
		delete this->empDArr[i];

	delete this->empDArr;

	for (int i = 0; i < this->cClassArrNum; i++)
		delete this->ClassDArr[i];

	delete this->ClassDArr;
}

void CoronaVirusCrisisManagement:: Menu () // Main function
{
	int option;
	bool run = true;
	while (run) {
		printOptions();
		cin >> option;
		switch (option) {
		case ADD_NURSE:
			AddNurse();
			break;
		case ADD_DOCTOR:
			AddDoctor();
			break;
		case ADD_DEPARTMENT:
			AddDepartment();
			break;
		case PRINT_DEPARTMENT_DETAILS:
			PrintDepartmentDetails();
			break;
		case PRINT_DOCTORS_DETAILS:
			PrintDoctorsDetails();
			break;
		case PRINT_SALARY_BY_ID:
			PrintSalary();
			break;
		case ADD_PATIENT:
			AddPatient();
			break;
		case ADD_CORONA_TEST_TO_PATIENT_ID:
			AddCoronaTestToPatientById();
			break;
		case RELEASING_PATIENTS:
			Releasing();
			break;
		case PRINT_EXCELLENCE_WORKER:
			PrintExcellenceWorker();
			break;
		case PRINT_NURSE_DETAILS_WITH_SMALLEST_SALARY:
			PrintNurseWithSmallestSalary();
			break;
		case EXIT:
			run = false;
			break;
		}
	}
}

void CoronaVirusCrisisManagement::printOptions()const 
{
	cout << "Menu: " << endl;
	cout << "1. ADD NURSE" << endl;
	cout << "2. ADD DOCTOR" << endl;
	cout << "3. ADD DEPARTMENT" << endl;
	cout << "4. PRINT DEPARTMENT DETAILS" << endl;
	cout << "5. PRINT DOCTORS DETAILS" << endl;
	cout << "6. PRINT SALARY BY ID" << endl;
	cout << "7. ADD PATIENT" << endl;
	cout << "8. ADD CORONA TEST TO PATIENT ID" << endl;
	cout << "9. RELEASING PATIENTS" << endl;
	cout << "10. PRINT EXCELLENCE WORKER" << endl;
	cout << "11. PRINT NURSE DETAILS WITH SMALLEST SALARY" << endl;
	cout << "12. EXIT" << endl;

	string HospitalNames[] = { "Sheba", "Wolfson" , "Rambam", "Assaf Harofeh", "Soroka" };
	{
		Doctor* help;
	string HospitalNames[] = { "Sheba", "Wolfson" , "Rambam", "Assaf Harofeh", "Soroka" };
	string ho;
	cout << '{';
	for (int i = 0; i < N; i++)
	{
		cout << HospitalNames[i];
		cout << ' ';
	}
	cout << '}';

	cout << "\nEnter a name of hospital from the list to add a patient: " << endl;
	cin >> ho;

	string hos, name, lname, id;
	int cTests, ncTests;

	cout << "Enter ID: " << endl;
	cin >> id;

	for (int j = 0; j < this->pArrNum; j++)
	{
		if (this->PatDArr[j]->getId() == id)
		{
			cout << "Patient alreday exist!" << endl;
			exit(1);
		}
	}

	cout << "Enter name of the patient: " << endl;
	cin >> name;
	cout << "Enter last name of the patient: " << endl;
	cin >> lname;
	cout << "Enter corona test's number: " << endl;
	cin >> cTests;
	cout << "Enter NEGATIVE corona test's number: " << endl;
	cin >> ncTests;

	Patient P(name, lname, id, ho, cTests, ncTests);

	for (int i = 0; i < this->pArrNum; i++)
	{
		if (this->PatDArr[i]->getDepart() == hos)
		{
			Patient ** temp;
			temp = new Patient*[this->pArrNum];

			for (int j = 0; j < this->pArrNum; j++)
				temp[j] = PatDArr[j];

			for (int j = 0; j < this->pArrNum; j++)
				delete this->PatDArr[j];

			delete[] this->PatDArr;

			this->pArrNum += 1;
			PatDArr = new Patient *[this->pArrNum];

			for (int j = 0; j < this->pArrNum - 1; j++)
				PatDArr[j] = temp[j];


			for (int j = 0; j < this->pArrNum - 1; j++)
				delete temp[j];

			delete[] temp;


		}
		this->ClassDArr[pArrNum - 1]->addPatient(&P);
	}


}
	string _id;
	for (int i = 0; i < this->pArrNum; i++)
	{
		if (this->PatDArr[i]->getNCT() == 2)
			delete this->PatDArr[i];
			
	}


	for (int i = 0; i < this->empArrNum; i++)
	int _min = MIN,index;