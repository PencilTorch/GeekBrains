#include <iostream>
#include <random>
#include <list>
using namespace std;

void averagePushBack(list<double>& lst) {
    if(lst.size() > 1) {
    	double sum = 0;
    	for (const auto& it : lst)
        	sum += it;
    	lst.push_back(sum / static_cast<double>(lst.size()));
	}
}

void printList(const list<double>& lst) {
    for (const auto& it : lst)
        cout << it << endl;
}

int main() {
    double lower_bound = 0;
    double upper_bound = 10000;
    uniform_real_distribution<double> unif(lower_bound, upper_bound);
    default_random_engine re;
    
    list<double> lst;
    for (int i = 0; i < 5; i++) {
        lst.push_back(unif(re));
    }

    printList(lst);
    cout << "add arithmetic mean to the end of the list...\n";
    averagePushBack(lst);
    averagePushBack(lst);
    averagePushBack(lst);
    printList(lst);
    

    return 0;
}