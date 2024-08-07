#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    long long k[n];
    for (int i = 0; i < n; i++)
    {
        cin >> k[i];
    }
    int start = 0;
    int max_length = 1;
    map<int, int> pos;
    for (int i = 0; i < n; i++)
    {
        if (pos.count(k[i]) != 0 && pos[k[i]]>=start)
        {   
            // cout<<pos[k[i]]<<" ";
            start = pos[k[i]]+1;
            pos[k[i]]=i;
        }
        else
        {
            pos[k[i]] = i;
        }
        // for (int j=start;j<i;j++)
        // {
        //     if(k[j]==k[i])
        //     {
        //         start=j+1;
        //         break;
        //     }
        // }
        
        max_length = max(max_length, i - start + 1);
        // cout<<start<<" "<<max_length<<"\n";
    }
    cout << max_length;
}