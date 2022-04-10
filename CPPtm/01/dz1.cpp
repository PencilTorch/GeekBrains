#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <tuple>
#include <algorithm>
#include <iomanip>
#include <optional>
using namespace std;

// task 1
struct Person {
	Person(const string& fn = "", const string& sn = "", const optional<string>& tn ="") : f_name(fn), s_name(sn), t_name(tn) {}
	Person(const tuple<string, string, string>& t) {
		tie(f_name, s_name, t_name) = t;
	};
	friend ostream& operator<<(ostream& out, const Person& p);
	friend bool operator<(const Person& fst, const Person& snd);
	friend bool operator==(const Person& fst, const Person& snd);

	string f_name;
	string s_name;
	optional<string> t_name;
};
ostream& operator<<(ostream& out, const Person& p) {
	out.setf(ios::left);
	if (p.t_name != nullopt)
		out << setw(12) << p.f_name << setw(10) << p.s_name << setw(15) << *(p.t_name) << " ";
	else
		out << setw(12) << p.f_name << setw(10) << p.s_name << setw(16) << "";
	return out;
}
bool operator<(const Person& fst, const Person& snd) {
	return tie(fst.f_name, fst.s_name, fst.t_name) < tie(snd.f_name, snd.s_name, snd.t_name);
}
bool operator==(const Person& fst, const Person& snd) {
	return tie(fst.f_name, fst.s_name, fst.t_name) == tie(snd.f_name, snd.s_name, snd.t_name);
}

// task 2
struct PhoneNumber {
	PhoneNumber() : countryCode(0), townCode(0), number(""), extNumber(0) {}
	PhoneNumber(const int cc, const int tc, const string& num, const optional<int> en) {
		countryCode = cc;
		townCode = tc;
		number = num;
		extNumber = en;
	}
	PhoneNumber(tuple<int, int, string, int>& phn) {
		tie(countryCode, townCode, number, extNumber) = phn;
	}
	PhoneNumber& operator=(const PhoneNumber& other) {
		countryCode = other.countryCode;
		townCode = other.townCode;
		number = other.number;
		extNumber = other.extNumber;
		return *this;
	}
	friend ostream& operator<<(ostream& out, const PhoneNumber& pn);
	friend bool operator<(const PhoneNumber& fst, const PhoneNumber& snd);
	friend bool operator==(const PhoneNumber& fst, const PhoneNumber& snd);

	int countryCode;
	int townCode;
	string number;
	optional<int> extNumber;
};
ostream& operator<<(ostream& out, const PhoneNumber& pn) {
	if (pn.extNumber != nullopt)
		return out << "+" << pn.countryCode << "(" << pn.townCode << ")" << pn.number << " " << *(pn.extNumber) << "\n";
	else
		return out << "+" << pn.countryCode << "(" << pn.townCode << ")" << pn.number << "\n";
}
bool operator<(const PhoneNumber& fst, const PhoneNumber& snd) {
	return tie(fst.countryCode, fst.townCode, fst.number, fst.extNumber) <
		tie(snd.countryCode, snd.townCode, snd.number, snd.extNumber);
}
bool operator==(const PhoneNumber& fst, const PhoneNumber& snd) {
	return tie(fst.countryCode, fst.townCode, fst.number, fst.extNumber) ==
		tie(snd.countryCode, snd.townCode, snd.number, snd.extNumber);
}

// task 3
class PhoneBook {
public:
	PhoneBook(ifstream& fin) {
		if (fin.is_open()) {
			string str;
			Person pers;
			PhoneNumber phone;
			while (!fin.eof()) {
				getline(fin, str);
				size_t pos = 0;
				size_t count = 0;
				count = str.find(" ", pos);
				pers.f_name = str.substr(pos, count);
				pos = count + 1;
				count = str.find(" ", pos);
				pers.s_name = str.substr(pos, count - pos);
				pos = count + 1;
				count = str.find(" ", pos);
				if (str.substr(pos, count - pos) != "-")
					pers.t_name = str.substr(pos, count - pos);
				else
					pers.t_name = nullopt;
				pos = count + 1;
				count = str.find(" ", pos);
				phone.countryCode = stoi(str.substr(pos, count - pos));
				pos = count + 1;
				count = str.find(" ", pos);
				phone.townCode = stoi(str.substr(pos, count - pos));
				pos = count + 1;
				count = str.find(" ", pos);
				phone.number = str.substr(pos, count - pos);
				pos = count + 1;
				if (str.substr(pos) != "-")
					phone.extNumber = stoi(str.substr(pos));
				else
					phone.extNumber = nullopt;
				pair<Person, PhoneNumber> temp(pers, phone);
				phone_base.push_back(temp);
			}
		}
		else
			cout << "file don't open!\n";
		fin.close();
	}
	void SortByPhone() {
		sort(phone_base.begin(), phone_base.end(), [](pair<Person, PhoneNumber>fst, pair<Person, PhoneNumber>snd) {
			return fst.second < snd.second; });
	}
	void SortByName() {
		sort(phone_base.begin(), phone_base.end(), [](pair<Person, PhoneNumber>fst, pair<Person, PhoneNumber>snd) {
			return fst.first < snd.first; });
	}
	pair<string, optional<PhoneNumber>> GetPhoneNumber(const string& str) {
		PhoneNumber temp;
		bool count = false;
		for (const auto& it : phone_base) {
			if (it.first.f_name == str && count == false) {
				temp = it.second;
				count = true;
			}
			else if (it.first.f_name == str && count == true)
				return { "found more than 1", nullopt };
		}
		if (count)
			return { "", temp };
		else
			return { "not found", nullopt };
	}
	void ChangePhoneNumber(const Person& p, const PhoneNumber& phn) {
		for (auto& it : phone_base) {
			if (tie(it.first.f_name, it.first.s_name, it.first.t_name) == tie(p.f_name, p.s_name, p.t_name)) {
				it.second = phn;
				break;
			}
		}
	}
	friend ostream& operator<<(ostream& out, const PhoneBook& phb);
private:
	vector<pair<Person, PhoneNumber>> phone_base;
};

ostream& operator<<(ostream& out, const PhoneBook& phb) {
	for (const auto& it : phb.phone_base)
		out << it.first << it.second;
	return out;
}

int  main() {
	ifstream file("PhoneBook.txt"); // путь к файлу PhoneBook.txt
	PhoneBook book(file);
	cout << book;

	cout << "------SortByPhone-------" << endl;
	book.SortByPhone();
	cout << book;

	cout << "------SortByName--------" << endl;
	book.SortByName();
	cout << book;

	cout << "-----GetPhoneNumber-----" << endl;
	// лямбда функция, которая принимает фамилию и выводит номер телефона
	// этого человека, либо строку с ошибкой

	auto print_phone_number = [&book](const string& surname) {
		cout << surname << "\t";
		auto answer = book.GetPhoneNumber(surname);
		if (get<0>(answer).empty())
			cout << *get<1>(answer);
		else {
			cout << get<0>(answer);
			cout << endl;
		}
	};
	// вызовы лямбды
	print_phone_number("Ivanov");
	print_phone_number("Petrov");

	cout << "----ChangePhoneNumber----" << endl;
	book.ChangePhoneNumber(Person{ "Kotov", "Vasilii", "Eliseevich" },
		PhoneNumber{ 7, 123, "15344458", nullopt });
	book.ChangePhoneNumber(Person{ "Mironova", "Margarita", "Vladimirovna" },
		PhoneNumber{ 16, 465, "9155448", 13 });
	cout << book;

	return 0;
}