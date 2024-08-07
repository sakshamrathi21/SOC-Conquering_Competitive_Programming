#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long x,n;
    cin>>x>>n;
    // long long d[n];
    priority_queue<long long int,vector<long long int>,greater<long long int>> d;
    for (int i=0;i<n;i++)
    {
        long long di;
        cin>>di;
        d.push(di);
    }
    long long mincost = 0;
    while(d.size()>1)
    {
        long long w1,w2;
        w1=d.top();
        d.pop();
        w2=d.top();
        d.pop();
        long long w = w1+w2;
        mincost+=w;
        d.push(w);
    }
    cout<<mincost;
}