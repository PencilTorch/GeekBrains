#include <iostream>
#include <string>


class Person {
public:
	Person() {
		this->name = "";
		this->age = 0;
		this->gender = 0;
		this->weight = 0;
	}
	Person(std::string name, unsigned short age, bool gender, unsigned short weight) {
		this->name = name;
		this->age = age;
		this->gender = gender;
		this->weight = weight;
	}
	void setName(std::string name) {
		this->name = name;
	}
	void setAge(unsigned short age) {
		this->age = age;
	}
	void setGender(bool gender) {
		this->gender = gender;
	}
	void setWeight(unsigned short weight) {
		this->weight = weight;
	}
	std::string getName() const {
		return this->name;
	}
	unsigned short getAge() const {
		return this->age;
	}
	std::string getGender() const {
		std::string str = "Female";
		if (this->gender)
			str =  "Male";
		return str;
	}
	unsigned short getWeight() const {
		return this->weight;
	}
private:
	std::string name;
	unsigned short age;
	bool gender;
	unsigned short weight;
};

class Student : public Person {
public:
	static unsigned short count;
	Student() {
		year_of_study = 0;
		++count;
		id = count;
	}
	void setYearOfStudy(unsigned short year) {
		this->year_of_study = year;
	}
	void addYearOfStudy() {
		year_of_study++;
	}
	unsigned short getId() const {
		return this->id;
	}
	unsigned short getYOS() const {
		return this->year_of_study;
	}
private:
	unsigned short year_of_study;
	unsigned short id;
};

unsigned short Student::count = 0;


void printStudentInfo(Student& student) {
	std::cout << student.getId() << ". Name: " << student.getName() << ", age: " << student.getAge() << ", gender: "
	<< student.getGender() << ", weight: " << student.getWeight() << ", year of study: " << student.getYOS() << std::endl;
}

int main() {
	Student student1;
	student1.setName("Ivan Govnov");
	student1.setAge(18);
	student1.setGender(1);
	student1.setWeight(75);
	student1.setYearOfStudy(2010);
	Student student2;
	student2.setName("Sasha Grey");
	student2.setAge(19);
	student2.setGender(0);
	student2.setWeight(55);
	student2.setYearOfStudy(2007);
	Student student3;
	student3.setName("Fedor Konyuhoff");
	student3.setAge(45);
	student3.setGender(1);
	student3.setWeight(85);
	student3.setYearOfStudy(2001);
	printStudentInfo(student1);
	printStudentInfo(student2);
	printStudentInfo(student3);

	return 0;
}