class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;
        vector<int> ans;
        for (int i = 0; i < k; i++) {
            int element = nums[i];
            while (!dq.empty() && nums[dq.back()] <= element) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        ans.push_back(nums[dq.front()]);

        for (int i = k; i < n; i++) {
            int element = nums[i];
            while (!dq.empty() && nums[dq.back()] <= element) {
                dq.pop_back();
            }
            dq.push_back(i);
            if (i - dq.front() >= k && !dq.empty())
                dq.pop_front();
            ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};