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
}void CoronaVirusCrisisManagement::AddNurse(){	string hos,name,lname,id;	int years, courses;	cout << "Enter name of hospital to add a nurse details: " << endl;	cin >> hos;	cout << "Enter ID: " << endl;	cin >> id;	for (int j = 0; j < this->empArrNum; j++)	{		if (this->empDArr[j]->getId() == id)		{			cout << "Nurse alreday exist!" << endl;			exit(1);		}	}	cout << "Enter name of the nurse: " << endl;	cin >> name;	cout << "Enter last name of the nurse: " << endl;	cin >> lname;	cout << "Enter years of seniority: " << endl;	cin >> years;	cout << "Enter number of courses: " << endl;	cin >> courses;	Nurse Nu(name, lname, id, years, hos, courses);	for (int i = 0; i < this->cClassArrNum; i++)	{		if (this->ClassDArr[i]->getHospitalName() == hos)		{			 Employee ** temp;			 temp = new Employee*[this->empArrNum];			 for (int j = 0; j < this->empArrNum; j++)				 temp[j] = empDArr[j];			 for (int j = 0; j < this->empArrNum; j++)				 delete this->empDArr[j];			 delete[] this->empDArr;			 this->empArrNum += 1;			 empDArr = new Employee *[this->empArrNum];			 for (int j = 0; j < this->empArrNum - 1; j++)				 empDArr[j] = temp[j];			 for (int j = 0; j < this->empArrNum-1; j++)				 delete temp[j];			 delete [] temp;		}			this->ClassDArr[empArrNum - 1]->addNurse(&Nu);	}	}void CoronaVirusCrisisManagement::AddDoctor(){	string hos, name, lname, id;	int years, pos,ch;	bool pr;	cout << "Enter name of hospital to add a doctor details: " << endl;	cin >> hos;	cout << "Enter ID: " << endl;	cin >> id;	for (int j = 0; j < this->empArrNum; j++)	{		if (this->empDArr[j]->getId() == id)		{			cout << "Doctor alreday exist!" << endl;			exit(1);		}	}	cout << "Enter name of the doctor: " << endl;	cin >> name;	cout << "Enter last name of the doctor: " << endl;	cin >> lname;	cout << "Enter years of seniority: " << endl;	cin >> years;	cout << "Enter number of positive assessments: " << endl;	cin >> pos;	cout << "The doctor is proffessor? \n 1-YES,2-NO " << endl;	cin >> ch;	if (ch)		pr = true;	else		pr = false;	Doctor D(name, lname, id, years, hos, pr, pos);	for (int i = 0; i<this->cClassArrNum; i++)		if (this->ClassDArr[i]->getHospitalName() == hos)		{			Employee ** temp;			temp = new Employee*[this->empArrNum];			for (int j = 0; j < this->empArrNum; j++)				temp[j] = empDArr[j];			for (int j = 0; j < this->empArrNum; j++)				delete this->empDArr[j];			delete[] this->empDArr;			this->empArrNum += 1;			empDArr = new Employee *[this->empArrNum];			for (int j = 0; j < this->empArrNum - 1; j++)				empDArr[j] = temp[j];			for (int j = 0; j < this->empArrNum - 1; j++)				delete temp[j];			delete[] temp;		}					this->ClassDArr[empArrNum - 1]->addDoctor(&D);}void CoronaVirusCrisisManagement::AddDepartment(){
	string HospitalNames[] = { "Sheba", "Wolfson" , "Rambam", "Assaf Harofeh", "Soroka" };	string hos;	cout << HospitalNames << endl;	cout << "Enter a name of hospital from the list to add a corona department: " << endl;	cin >> hos;	for (int i = 0; i < N; i++)	{		if (hos == (HospitalNames)[i])		{			for (int j=0;j<this ->cClassArrNum;j++)				if (this->ClassDArr[j]->getHospitalName() == hos)				{					CoronaVirusCrisisManagement add;				}		}	}}void CoronaVirusCrisisManagement::PrintDepartmentDetails() const{	string HospitalNames[] = { "Sheba", "Wolfson" , "Rambam", "Assaf Harofeh", "Soroka" };	string hos;	cout << '{';	for (int i = 0; i < N; i++)	{		cout << HospitalNames[i];		cout << ' ';	}	cout << '}';	cout << "\nEnter a name of hospital from the list to print a corona department: " << endl;	cin >> hos;	for (int i = 0; i < N; i++)	{		if (hos == HospitalNames[i])		{			for (int j = 0; j < this->cClassArrNum; j++)			{					(*ClassDArr)[j].printCoronaClass();			}		}	}}void CoronaVirusCrisisManagement::PrintDoctorsDetails() const // using rtti{	for (int i = 0; i < this->empArrNum; i++)
	{
		Doctor* help;		help = dynamic_cast<Doctor*> (this->empDArr[i]);		if (help)			(*empDArr)[i].printEmployee();	}} void CoronaVirusCrisisManagement::PrintSalary() const {	string id;	cout << "Enter id of worker " << endl;	cin >> id;	int flag = 0;	for (int i = 0; i < this->empArrNum; i++)	{		if (id == this->empDArr[i]->getId())		{			(*empDArr)[i].printEmployee();			flag = 1;		}	}	if (!flag)		cout << "ID not found!" << endl;}void CoronaVirusCrisisManagement::AddPatient(){
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


}void CoronaVirusCrisisManagement::AddCoronaTestToPatientById(){
	string _id;	int choise;	cout << "Enter id of patient: " << endl;	cin >> _id;	cout << "The test result is: 1-POSITIVE , 0-NEGATIVE" << endl;	cin >> choise;	int num = 0;	int flag = 0;	for (int i = 0; i < this->pArrNum; i++)	{		if (this->PatDArr[i]->getId() == _id)		{			if (choise)			{ 				num = this -> PatDArr[i]->CT() +1;				this ->PatDArr[i]->setCT(num);				flag = 1;			}			else			{ 				num = this->PatDArr[i]->NCT() + 1;				this->PatDArr[i]->setNCT(num);				flag = 1;			}		}	}	if (!flag)	{		cout << "\nID not found!";			}}void CoronaVirusCrisisManagement::Releasing(){
	for (int i = 0; i < this->pArrNum; i++)
	{
		if (this->PatDArr[i]->getNCT() == 2)
			delete this->PatDArr[i];
			
	}
}void CoronaVirusCrisisManagement::PrintExcellenceWorker() const //using virtual func{

	for (int i = 0; i < this->empArrNum; i++)		this->empDArr[i]->isOutstanding();}void CoronaVirusCrisisManagement::PrintNurseWithSmallestSalary() const // using rtti{
	int _min = MIN,index;	Nurse * help;	for (int i = 0; i < this->empArrNum; i++)	{		help = dynamic_cast <Nurse*> (this->empDArr[i]);		if (help)		{			if (this->empDArr[i]->getSalary() < _min)				index = i;		}	}	for (int i = 0; i < this->empArrNum; i++)		if (i == index)			empDArr[i]->printEmployee();}