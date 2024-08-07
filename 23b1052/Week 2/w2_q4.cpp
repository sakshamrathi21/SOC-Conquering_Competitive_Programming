class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>&arr, int k) {
        int n = arr.size();
        set<pair<int,int>>hs;
        for(int i = 0; i < k;i++) hs.insert({arr[i],i});
        vector<int>ans;
        ans.push_back((--hs.end())->first);
        for(int i = 0;i<n-k;i++){
            hs.erase({arr[i],i});
            hs.insert({arr[i+k],i+k});
            ans.push_back((--hs.end())->first);
        }
        return ans;
    }
};