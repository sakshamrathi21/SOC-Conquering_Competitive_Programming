#include <bits/stdc++.h>
#include<iostream>
#include<vector>
#include<stdlib.h>
#include<algorithm>
#define REP(i,a,b) for(int i=a;i<b;i++)

using namespace std;


int main()
{
    int n;
    cin >> n;
    int arr[n];

    REP(i,0,n)
    {
        cin >> arr[i];
    }

    map<int,int> check;
    int maximum=0;

    int a=0;
    int b=0;
    REP(i,0,n) 
    {
        if(check.count(arr[b]) & check[arr[b]]>=a)
        {
            a=check[arr[b]]+1;
            check[arr[b]]=b;
            //cout << a << " " << b << "\n" ; 
            
        }

        else
        {
            check[arr[b]]=b;
            //cout << a << " " << b << "\n" ; 
            
        }
        b++;
        maximum=max(maximum,b-a);
    }
    
    cout << maximum << "\n";
    
}
    

