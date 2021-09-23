#include <iostream>
#include <string>
#include <fstream>
using namespace std;
static unsigned short id = 0;
#pragma pack(push,1)
struct worker{
	worker(string fN, string sN, unsigned short age, unsigned int dp, float sc, string fn) {
		idWorker = ++id;
		this->fName = fN;
		this->sName = sN;
		this->age = age;
		this->department = dp;
		this->salaryCoef = sc;
		this->foneNumber = fn;
	}
	unsigned short idWorker;
	string fName;
	string sName;
	unsigned short age;
	unsigned int department;
	float salaryCoef;
	string foneNumber;
	void printWorker() {
		cout << "id worker: " << idWorker << endl;
		cout << "first name: " << fName << endl;
		cout << "second name: " << sName << endl;
		cout << "age: " << age << endl;
		cout << "department: " << department << endl;
		cout << "salary coeficient: " << salaryCoef << endl;
		cout << "fone namber: " << foneNumber << endl;
	}
};
#pragma pack(pop)

void saveInFile(worker& other) {
	ofstream fout("worker.txt", ofstream::app);
	if (fout.is_open()) {
		fout << other.idWorker << endl;
		fout << other.fName << endl;
		fout << other.sName << endl;
		fout << other.age << endl;
		fout << other.department << endl;
		fout << other.salaryCoef << endl;
		fout << other.foneNumber << endl;
	}
	fout.close();
}

int main() {
	
	worker* worker1 = new worker("Ivan", "Ivanov", 25, 49, 0.9, "8 (499) 123-45-67");
	worker1->printWorker();
	cout <<"sizeof struct worker: "<< sizeof(worker) << endl;
	saveInFile(*worker1);

	delete worker1;

return 0;
}

