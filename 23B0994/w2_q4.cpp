#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

#define fr(a,b) for(lli i=a;i<b;i++)  // from a to b-1
#define reach cout<<"reached"<<endl
#define p1(a) cout<<a //for printing
#define pn1(a) cout<<a<<"\n"
typedef int64_t lli;
typedef vector<lli> vlli;
typedef vector<int> vi;
typedef vector<float> vf;

template <typename T>  
ostream & operator<< (ostream & ost, const vector<T> & vecty){
    fr (0,vecty.size()) {
        ost << vecty[i] << " ";
    }
    return ost;
}



    
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> vans;
        vector<int> vect1; //sorted vector
        for(int i=0;i<k;i++){
            vect1.push_back(nums[i]);
        }
        sort(vect1.begin(),vect1.end());
        vans.push_back(vect1[k-1]);
        int m=nums.size();
        for(int i=0;i<m-k;i++){
            vect1.erase(lower_bound(vect1.begin(),vect1.end(),nums[i]));
            vect1.insert(upper_bound(vect1.begin(),vect1.end(),nums[k+i]),nums[k+i]);
            vans.push_back(vect1[k-1]);
        }
        return vans;
        
        
    }
};
    

