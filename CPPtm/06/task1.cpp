#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>
using namespace std;

mutex m;

void pcout() {
	m.lock();
	cout << "start pcout in thread id " << this_thread::get_id() << endl;
	this_thread::sleep_for(1s);
	cout << "start pcout in thread id " << this_thread::get_id() << endl;
	m.unlock();
}

int  main() {
	thread th1(pcout);
	thread th2(pcout);
	thread th3(pcout);
	th1.join();
	th2.join();
	th3.join();

	return 0;
}
