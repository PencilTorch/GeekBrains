#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <deque>

using namespace std;

template< template<typename, typename> class A, typename B >
void insert_sorted(A<B, allocator <B>> &v, B n) {
    auto it = lower_bound(v.begin(), v.end(), n);
    A<B, allocator <B>> t(1, n);
    copy(t.begin(), t.end(), inserter(v, it));
}

int main() {
    // vector int
    vector<int> v;
    v.resize(10);
    generate(v.begin(), v.end(), []() { return rand() % 100; });
    sort(v.begin(), v.end());
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    insert_sorted<vector, int>(v, 55);
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    // list string
    const char* s[5] = { "a1", "b2", "c3", "d4", "e5" };
    list<string> str(s, s + 5);
    insert_sorted<list, string>(str, "b4");
    copy(str.begin(), str.end(), ostream_iterator<string>(cout, " "));
    cout << endl;
    // deque char
    char c[5] = { 'b', 'c', 'd', 'e', 'f'};
    deque<char> dq(c, c + 5);
    insert_sorted<deque, char>(dq, 'a');
    copy(dq.begin(), dq.end(), ostream_iterator<char>(cout, " "));

    return 0;
}