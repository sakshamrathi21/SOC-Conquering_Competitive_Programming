#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> max;
        if(nums.size()==1) return nums;
        deque<int> dq;
        
        for(int i=0;i<nums.size();i++){
            while(!dq.empty() && nums[dq.back()] <= nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);  

            if(i>=k-1){
                max.push_back(nums[dq.front()]);
            }
            if((i - dq.front()) >= k-1){
                dq.pop_front();
            }
               
    }
    return max;
}
};

