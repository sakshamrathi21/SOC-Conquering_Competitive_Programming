#include <bits/stdc++.h>
#include<iostream>
#include<vector>
#include<stdlib.h>
#include<algorithm>
#define REP(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int main()
{
    int n,x;
    cin >> n >> x;
    vector<int> arr ,real ;
    REP(i,0,n)
    {
        int k;
        cin >> k;
        arr.push_back(k);
        real.push_back(k);
    } 

    sort(arr.begin(),arr.end());
    int a=0;
    int b=n-1;
    REP(i,0,n)
    {
        if(a==b)
        {
            cout << "IMPOSSIBLE" << "\n";
            break; 
        }

        else if(arr[a]+arr[b]<x)
        {
            a++;
        }
        else if(arr[a]+arr[b]>x)
        {
            b--;
        }
        else if(arr[a]+arr[b]==x)
        {
            //cout << arr[a] << " " << arr[b] << "\n";
            break;
        }
        
    }

if(a!=b){
    int p=0,q=0;
    REP(i,0,n)
    {
        if(arr[a]==real[p])
        {
            cout << p+1;
            break;
        }
        p++;
    }
    REP(i,0,n)
    {
        if(arr[b]==real[q] & p!=q)
        {
            cout << " " << q+1;
            break;
        }
        q++;
    }

    cout << "\n";
}


}