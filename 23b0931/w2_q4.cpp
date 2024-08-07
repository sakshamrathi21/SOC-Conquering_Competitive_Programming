#include<bits/stdc++.h>
using namespace std;

// *******  Works but time limit exceeds ************//
/*
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res ;
        queue<int> q ;
        q.push(nums[0]);
        int p = k-1 , removal = 0;
        for(int j = 1 ; j<=p ; j++){
            if(q.back()< nums.at(j)) q.push(nums.at(j));
        }
        res.push_back(q.back()) ;
        p ++ ; 
        while(p<nums.size()){
            if(q.front() == nums.at(removal)) q.pop() ; 
            if(! q.empty() )if(q.back() < nums.at(p)) q.push(nums.at(p));
            if(q.empty()) {
                q.push(nums.at(p-(k-1)));
                for(int j = p-(k-2) ; j<=p ; j++){
                    if(q.back()< nums.at(j)) q.push(nums.at(j));
                }
            }
            res.push_back(q.back()) ;
            p ++ ; removal ++ ;
        }
        return res ;
}
*/

vector<int> maxwindowslide(vector<int> v , int k){
    deque<int> dq;
    vector<int> res ;
    for(int i = 0  ; i < v.size() ; i++){
        if(! dq.empty() && i>=k && dq.front() == v[i-k]) dq.pop_front();
        while(! dq.empty() && dq.back() < v[i]) dq.pop_back();
        dq.push_back(v[i]) ; 
        if(i>=k-1) res.push_back(dq.front()); 
    }
    return res ;
}

int main(){
    vector<int> nums = {1,3,-3,-1,-5,3,6,7};
    // vector<int> nums = {1,-1};
    int k = 3;
    vector<int> res = maxwindowslide(nums,k);
    for(int i = 0 ; i<res.size() ; i++){
        cout<<res.at(i)<<" ";
    }
    return 0;
}