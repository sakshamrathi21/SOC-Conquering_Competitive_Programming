#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    // Sort the stick lengths to find the median
    sort(v.begin(),v.end());

    // The median is the best length to minimize the total cost
    int median = v[n / 2];

    long long cost = 0;
    for (int i = 0; i < n; ++i) {
        cost += abs(v[i] - median);
    }

    cout << cost << endl;
}

