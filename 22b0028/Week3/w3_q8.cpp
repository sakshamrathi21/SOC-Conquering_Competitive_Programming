#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> nums(n);
    vector<long long> nums2(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        nums2[i] = nums[i];
    }

    sort(nums2.begin(), nums2.end());
    vector<long long> list;
    list.push_back(nums2[0]);
    for (int i = 1; i < n; i++) {
        if (list.back() != nums2[i]) {
            list.push_back(nums2[i]);
        }
    }

    int k = list.size();

    vector<long long> prevRow(k);
    prevRow[0] = abs(nums[0] - list[0]);

    for (int i = 1; i < k; i++) {
        prevRow[i] = min(prevRow[i - 1], abs(nums[0] - list[i]));
    }

    vector<long long> col1(n);
    col1[0] = abs(nums[0] - list[0]);
    for (int i = 1; i < n; i++) {
        col1[i] = col1[i - 1] + abs(nums[i] - list[0]);
    }

    for (int i = 1; i < n; i++) {
        vector<long long> currRow(k);
        currRow[0] = col1[i];
        for (int j = 1; j < k; j++) {
            currRow[j] = min(currRow[j - 1], prevRow[j] + abs(nums[i] - list[j]));
        }
        prevRow = currRow;
    }

    cout << prevRow[k - 1] << endl;

    return 0;
}
