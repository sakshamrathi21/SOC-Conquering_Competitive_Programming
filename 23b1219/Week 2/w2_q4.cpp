class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    multiset<pair<int, int>>m;
    vector<int>r;
    for(int i=0; i<nums.size(); i++){
        if(i<k){
            m.insert({nums[i], i});
        }
        else{
            auto it = m.end();
            it--;
            auto a= it->first;
            r.push_back(a);
            m.erase({nums[i-k], i-k});
            m.insert({nums[i], i});
        }
    }
    auto it = m.end();
    it--;
    auto a= it->first;
    r.push_back(a);
    return r;
    }
};