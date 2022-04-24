#include <iostream>
#include <algorithm>
#include <numeric>
#include <random>
#include <vector>

using namespace std;

struct RandomGenerator {
    double lower_bound;
    double upper_bound;
    RandomGenerator(double min, double max) : lower_bound(min), upper_bound(max) {}
    double operator()() {
        random_device rd;
        default_random_engine eng(rd());
        uniform_real_distribution<double> distr(lower_bound, upper_bound);
        return distr(eng);
    }
};

double fallibility(const vector<double> &v1, const vector<int>& v2) {
    vector<double> temp;
    temp.resize(v1.size());
    for (size_t i = 0; i < v1.size(); ++i)
        temp[i] = v1[i] - v2[i];
    return accumulate(begin(temp), end(temp), 0., [](double x, double y) { return x + y * y; });
}

int main() {
    vector<double> a;
    a.resize(100);
    generate(a.begin(), a.end(), RandomGenerator(-50, 50));

    vector<int> b(100, 0);
    transform(a.begin(), a.end(), b.begin(), [](double d) { return static_cast<int>(d); });

    cout << "Analog signal:\n";
    copy(a.begin(), a.end(), ostream_iterator<double>(cout, " "));
    cout << endl;
    cout << "Digital signal:\n";
    copy(b.begin(), b.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    cout << "Signal conversion error: " << fallibility(a, b);

    return 0;
}