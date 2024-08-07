class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> window;
        for (int i = 0; i < k; i++) {
            while (!window.empty()) {
                if (window.back() < nums[i]) {
                    window.pop_back();
                } else {
                    break;
                }
            }
            window.push_back(nums[i]);
        }
        int first = *max_element(nums.begin(), nums.begin() + k);
        int n = nums.size();

        vector<int> maxwindow;
        maxwindow.push_back(first);
        for (int i = k; i < n; i++) {
            if(!window.empty() && window.front()==nums[i-k]) window.pop_front();
            while (!window.empty()) {
                if (window.back() < nums[i]) {
                    window.pop_back();
                } else {
                    break;
                }
            }
            window.push_back(nums[i]);
            maxwindow.push_back(window.front());
        }
        return maxwindow;
    }
};