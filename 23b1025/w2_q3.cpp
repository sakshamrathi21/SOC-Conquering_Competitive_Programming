#include <bits/stdc++.h>
#include<iostream>
#include<vector>
#include<stdlib.h>
#include<algorithm>
#define REP(i,a,b) for(long long i=a;i<b;i++)

using namespace std;


int main()
{
   long long n,x;
   cin >> n >> x;
   vector<long long> arr, real;
   REP(i,0,n)
   {
        long long k;
        cin >> k;
        arr.push_back(k);
        real.push_back(k);    
   }

    sort(arr.begin(),arr.end());


    for(int c=0;c<=n;c++)
    {
        if(c==n)
        {
            cout << "IMPOSSIBLE" << "\n";
            break;
        }
        int a=0;
        int b=n-1;
        REP(i,0,n)
        {
            if(a==b)
            {
                continue;
            }

            else if(arr[a]+arr[b]<x-arr[c])
            {
                a++;
            }
            else if(arr[a]+arr[b]>x-arr[c])
            {
                b--;
            }   
            else if(arr[a]+arr[b]==x-arr[c])
            {
            //cout << arr[a] << " " << arr[b] << "\n";
                break;
            }
        }
        if(a!=c & b!=c & a!=b)
        {
            if(arr[a]+arr[b]+arr[c]==x)
            // cout << arr[a] << " " << arr[b] << " " << arr[c] << "\n";
            
            int x;
            int y;
            int z;

            for(x=0;x<n;x++)
            {
                if(arr[a]==real[x])
                {
                cout << x+1 << " ";
                break;
                }
            }

            for(y=n-1;y>=0;y--)
            {
                if(arr[b]==real[y])
                {
                cout << y+1 << " ";
                break;
                }
            }

            for(z=0;z<n;z++)
            {
                if(arr[c]==real[z])
                {
                    if(z!=x)
                    {
                    cout << z+1 << "\n";
                    break;
                    }
                }
            }

            break;
        }
    }
    
    


    
}
