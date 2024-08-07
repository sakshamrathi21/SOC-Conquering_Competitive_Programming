#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
using namespace std;

vector<int> minDiv;

void preprocessMinDiv(int maxVal) {
    minDiv.resize(maxVal + 1);
    iota(minDiv.begin(), minDiv.end(), 0);

    for (int i = 2; i <= maxVal; ++i) {
        if (minDiv[i] != i)
            continue;
        for (int j = i; j <= maxVal; j += i)
            minDiv[j] = min(minDiv[j], i);
    }
}

vector<int> getPrimeDivisors(int v) {
    vector<int> ans;
    while (v != 1) {
        if (ans.empty() || ans.back() != minDiv[v])
            ans.push_back(minDiv[v]);
        v /= minDiv[v];
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int maxVal = *max_element(a.begin(), a.end());
    preprocessMinDiv(maxVal);

    vector<int> d1(n, -1);
    vector<int> d2(n, -1);

    for (int id = 0; id < n; ++id) {
        vector<int> list = getPrimeDivisors(a[id]);
        if (list.size() < 2) {
            d1[id] = -1;
            d2[id] = -1;
        } else {
            d1[id] = list[0];
            list.erase(list.begin());
            d2[id] = accumulate(list.begin(), list.end(), 1, multiplies<int>());
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << d1[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < n; ++i) {
        cout << d2[i] << " ";
    }
    cout << endl;

    return 0;
}
