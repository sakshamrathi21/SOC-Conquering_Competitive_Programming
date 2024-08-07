#include <bits/stdc++.h>
#include<iostream>
#include<stdlib.h>
#include<algorithm>
#define REP(i,a,b) for(long long i=a;i<b;i++)

using namespace std;

int main()
{
    long long cost=0;
    long long n;
    cin >> n;
    long long arr[n];
    REP(i,0,n)
    {
        cin >>arr[i];
    }
    sort(arr,arr+n);
    
    REP(i,0,n/2)
    {
        cost +=arr[n/2]-arr[i];
    }
    
    REP(i,n/2,n)
    {
        cost +=arr[i]-arr[n/2];
    }

    cout << cost;
}