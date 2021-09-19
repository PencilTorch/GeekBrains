#include <iostream>
using namespace std;

#define INVITE(value1,value2) value1>=0&&value1<value2 ? cout<<"true\n" : cout<<"false\n"

int main() {

	INVITE(5, 10);
	INVITE(0, 10);
	INVITE(10, 10);
	
	return 0;
}