class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset <int> a;
        for(int i=0;i<k;i++) {
            a.insert(nums[i]);
        }
        vector<int> ans;
        ans.push_back(*a.rbegin());
        for(int i=k;i<nums.size();i++){
            a.erase(a.find(nums[i-k]));
            a.insert(nums[i]);
            ans.push_back(*a.rbegin());
        }
    return ans;
    }
};