#include<iostream>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#define REP(i,a,b) for(int i=a; i<b ;i++)
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> v(n,0);
    REP(i,0,n-1)
    {
        
        int a;
        cin >> a;
        v[a-1]=1;

    }
    
    REP(i,0,n)
    {
        if(v[i]==0)
        {
            cout << i+1 << "\n";
            break;
        }
    }


}