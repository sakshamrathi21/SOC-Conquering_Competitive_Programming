#include<bits/stdc++.h>
using namespace std;
int main(){
        long long int x;cin>>x;
        int n;cin>>n;
        vector<long long int> v(n);
        for(int i=0;i<n;i++){
                cin>>v[i];}

        priority_queue<int,vector<int>,greater<int>>q(v.begin(),v.end());
        long long int cost=0;
        while(q.size()>1){
                long long int x=q.top();q.pop();
                long long int y=q.top();q.pop();
                long long temp=x+y;
                cost+=temp;
                q.push(temp);}
        cout<<cost;
}

