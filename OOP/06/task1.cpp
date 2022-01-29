#include <iostream>
using namespace std;

// analog isdigit()
bool ifDigit(const string& str) {
	if (str.empty())
		return false;
	bool f = true;
	string::const_iterator it = str.begin();
	while(it != str.end()){
		if(*it < 48 || *it > 57){ //ANSII coding for number from 48 before 57
			f = false;
			break;
		}
		++it;
	}
	return f;
}

int main() {
    string number = "";
    getline(cin, number);
	while(!ifDigit(number)){
    	number.clear();
		cout<<"Input error! Repead the input.\n";
    	getline(cin, number);
	}
	cout<<number;

return 0;
}

