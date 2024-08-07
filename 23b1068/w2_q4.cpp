#include<bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& v, int k) {
    vector<int> ans;
    set<pair<int,int>> s;
    for(int i=0; i<k; i++){
        s.insert({v[i],i});
    }
    ans.push_back(s.rbegin()->first);
    for(int i=k; i<v.size(); i++){
        s.erase({v[i-1],i-1});
        s.insert({v[i],i});
        // cout << iter->second << "\n";
        ans.push_back((--s.end())->first);
    }
    return ans;
    
}

int main(){
    vector<int> v ={7,2,4};
    vector<int> ans =maxSlidingWindow(v, 2);
    for(int i = 0; i < ans.size(); i++) {
           cout << ans[i] << ' ';     
    }
}