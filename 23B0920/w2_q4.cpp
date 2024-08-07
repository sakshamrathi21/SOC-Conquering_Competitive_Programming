#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <set>
#include <map>
#include <list>
#include<deque>
#include<utility>
#define ll long long int
#define f1 for(int i=0; i<n; i++)
#define p1 for(int i=0; i<n; i++){cout<<a[i]<<' ';}
#define s1 while(t--)
#define ll long long int
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(k==1) return nums;
        else{
            vector<int> res;
            auto a=nums.begin();
            auto b=nums.begin()+k;

            deque<vector<int>::iterator> d;
            int maxi = *max_element(nums.begin(),b);
            auto maxi_pos_i=max_element(nums.begin(),b);
            int maxi_pos = distance(nums.begin(),max_element(nums.begin(),b));

            d.push_back(maxi_pos_i);
            for(auto i=nums.begin()+maxi_pos+1; i!=b; i++){
                while(*d.back()<*i){
                    d.pop_back();
                }
                d.push_back(i);
                
            }
            
            
            // cout<<*d.front()<<" "<<*d.back()<<endl;
            res.push_back(maxi);
            a++;b++;
            while(b!=(nums.end()+1)){
                // cout<<"me"<<endl;
                if(distance(maxi_pos_i,a)>0){

                    d.pop_front();
                    while(d.size()>0&&*d.back()<*(b-1)){
                        d.pop_back();
                    }
                    
                    d.push_back((b-1));
                    maxi_pos_i=d.front();
                    res.push_back(*maxi_pos_i);
                    a++;b++;
                    // cout<<"hi"<<*maxi_pos_i<<endl;



                }
                else{
                    while(d.size()>0&&*d.back()<*(b-1)){
                        d.pop_back();
                        // cout<<*d.back();
                    }
                    d.push_back((b-1));
                    // cout<<*d.back();
                    if(d.size()==1){maxi_pos_i=b-1;}
                    res.push_back(*maxi_pos_i);

                    // cout<<"hello"<<" "<<*maxi_pos_i<<endl;
                    a++;b++;
                }
        }
        return res;
        }

    }
};

    


