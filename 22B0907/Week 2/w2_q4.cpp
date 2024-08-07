class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ret;
        multiset<int, greater<int>> relavent;
        for(int i = 0; i < k; i++){
            relavent.insert(nums[i]);
        }
        ret.push_back(*(relavent.begin()));
        for(int i = k; i < n; i++){
            // Below is wrong because it erases all instances of nums[i-k]
            // relavent.erase(nums[i-k]);
            relavent.erase(relavent.find(nums[i-k]));
            relavent.insert(nums[i]);
            ret.push_back(*(relavent.begin()));
        }

        return ret;
    }
};