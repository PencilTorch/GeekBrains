#include <iostream>
#include <memory>
using namespace std;

// task 1
class Date {
public:
	Date(int day = 1, int month = 1, int year = 2022) : m_day(day), m_month(month), m_year(year) {}
	int getDay() const {
		return m_day;
	}
	int getMonth() const {
		return m_month;
	}
	int getYear() const {
		return m_year;
	}
	void setDay(int day) {
		m_day = day;
	}
	void setMonth(int month) {
		m_month = month;
	}
	void setYear(int year) {
		m_year = year;
	}
private:
	int m_day;
	int m_month;
	int m_year;
};

ostream& operator<< (ostream& out, const Date& date) {
	out << "Date: " << date.getDay() << ". " << date.getMonth() << ". " << date.getYear() << "\n";
	return out;
}

// task2
unique_ptr<Date>* getLastDate(unique_ptr<Date>& ptr1, unique_ptr<Date>& ptr2) {
	if (ptr1->getYear() > ptr2->getYear()) 
		return &ptr1;
	if (ptr1->getYear() == ptr2->getYear()) {
		if (ptr1->getMonth() > ptr2->getMonth()) 
			return &ptr1;
		if (ptr1->getMonth() == ptr2->getMonth()) {
			if(ptr1->getDay() > ptr2->getDay())
				return &ptr1;
			else
				return &ptr2;
		}
		else
			return &ptr2;
	}
	else
		return &ptr2;
}

void swapDate(shared_ptr<Date>& ptr1, shared_ptr<Date>& ptr2) {
	shared_ptr<Date> temp = make_shared<Date>();
	temp = ptr1;
	ptr1 = ptr2;
	ptr2 = temp;
}


int main() {

	Date date;
	cout << date;

	shared_ptr<Date> today = make_shared<Date>();
	today->setDay(30);
	today->setMonth(1);
	today->setYear(2022);
	cout << *today;
	auto day = today;
	cout << *day;
	if (today)
		cout << "today = nullptr\n";
	if (day)
		cout << "day = nullptr\n";

	unique_ptr<Date> date1 = make_unique<Date>(10, 01,2023);
	unique_ptr<Date> date2 = make_unique<Date>(15, 01, 2022);
	cout << **(getLastDate(date1, date2));
	
	shared_ptr<Date> date3 = make_shared<Date>(1,02,2022);
	shared_ptr<Date> date4 = make_shared<Date>(20, 02, 2022);
	swapDate(date3, date4);
	cout << *date3;

	return 0;
}
