#include<bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    int n = nums.size();
    deque<int> q; // We'll store indices here. 1st element is largest
    vector<int> ans; // We'll store maximum value of window.
    // We make the queue first k elements
    for (int i = 0; i<min(k, (int)nums.size()); ++i) {
        while(!q.empty() && nums[q.back()] < nums[i]) {
            q.pop_back();
        }
        q.push_back(i); // Making first window deque
    }
    ans.push_back(nums[q.front()]); // Pushing first window's max value
    for (int i = 0; i<n-k; ++i) {
        if (q.front() == i) {
            q.pop_front();
        }
        while(!q.empty() && nums[q.back()] < nums[i+k]) {
            q.pop_back();
        }
        q.push_back(i+k);
        ans.push_back(nums[q.front()]);
    }
    return ans;
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i<n; ++i) {
        cin >> nums[i];
    }
    vector<int> ans = maxSlidingWindow(nums, k);
    for (int i = 0; i<(int)ans.size(); ++i) {
        cout << ans[i] << " ";
    }
}