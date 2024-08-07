class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();
        deque<int> temp;
        temp.push_back(0);
        for(int i=0; i<k; i++){
            if(nums[*(temp.end()-1)]>nums[i]){
                temp.push_back(i);
            }
            else{
                while(temp.size()>0){
                    if(nums[*(temp.end()-1)]<=nums[i]){
                        temp.pop_back();
                    }
                    else break;
                }
                temp.push_back(i);
            }
        }
        ans.push_back(nums[*temp.begin()]);
        for(int i=k; i<n; i++){
            if(nums[*(temp.end()-1)]>nums[i]){
                temp.push_back(i);
            }
            else{
                while(temp.size()>0){
                    if(nums[*(temp.end()-1)]<=nums[i]){
                        temp.pop_back();
                    }
                    else break;
                }
                temp.push_back(i);
            }
            if(*temp.begin()<=i-k){
                temp.pop_front();
            }
            ans.push_back(nums[*temp.begin()]);
        }
        return ans;
    }
};