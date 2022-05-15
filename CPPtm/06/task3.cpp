#include <iostream>
#include <vector>
#include <algorithm>
#include <thread>
#include <mutex>
using namespace std;

mutex m1;
mutex m2;

void addItem(vector<int>& v) {
    for (int i = 0; i < 10; i++) {
        m1.lock();
        cout << "Owner in the house.\n";
        v.push_back(rand() % 100);
        copy(v.begin(), v.end(), ostream_iterator<int>(cout, "\n"));
        this_thread::sleep_for(1s);
        m1.unlock();
    } 
}

void stealItem(vector<int>& v) {
    for (int i = 0; i < 10; i++) {
        m2.lock();
        cout << "Robber in the house.\n";
        if (!v.empty()) {
            sort(v.begin(), v.end());
            v.pop_back();
            copy(v.begin(), v.end(), ostream_iterator<int>(cout, "\n"));
        }
        this_thread::sleep_for(500ms);
        m2.unlock();
    }
}


int main() {
    vector<int> items;

    thread owner(addItem, ref(items));
    thread robber(stealItem, ref(items));
    owner.join();
    robber.join();
   
    return 0;
}