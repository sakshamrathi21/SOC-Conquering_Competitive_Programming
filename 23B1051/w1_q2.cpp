#include<bits/stdc++.h>
#include<vector>
using namespace std;

int main(){
    string s;
    while(cin>>s){
        vector<int> counter_array;
        int count =1;
        for(int i=0;i<s.length();i++){
            if(s[i]==s[i+1]){
                count ++;
                continue;
            }
            else{
                counter_array.push_back(count);
                count=1;
                continue;
            }
        }
        sort(counter_array.begin(),counter_array.end());
        cout<<counter_array.back();
}
}