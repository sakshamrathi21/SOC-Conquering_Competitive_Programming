#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> sticks(n);
    for (int i = 0; i < n; ++i) {
        cin >> sticks[i];
    }
    sort(sticks.begin(), sticks.end());
    int median = sticks[n / 2];
    long long total_cost = 0;
    for (int i = 0; i < n; ++i) {
        total_cost += abs(sticks[i] - median);
    }
    cout << total_cost << endl;
    
    return 0;
}
