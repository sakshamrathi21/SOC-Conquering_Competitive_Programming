#include <bits/stdc++.h>
using namespace std;

void maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> result;
        deque<int> q;
        for(int i=0;i<n;i++){

                if((!q.empty()) && q.front()==i-k){
                        q.pop_front();}

                while(!q.empty()&& nums[q.back()]<nums[i]){
                        q.pop_back();}

                q.push_back(i);

                if(i>=k-1){
                        result.push_back(nums[q.front()]);}
        }

        int result_size=result.size();
        for(int i=0;i<result_size;i++){
                cout<<result[i]<<" ";}
        return;
}
int main(){
        int n,k;cin>>n>>k;
        vector<int> v(n);
        for(int i=0;i<n;i++){
                cin>>v[i];}
        maxSlidingWindow(v,k);
}
