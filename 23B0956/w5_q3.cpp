#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        string s;
        cin>>s;
        long long int n = s.length();
        bool no = false;
        for (int i=0;i<n-1;i++)
        {
            if (s[i]==48)
            {
                no=true;
                break;
            }
        }
        if (s[0]!=49 || s[n-1]==57 || no)
        {
            cout<<"NO"<<"\n";
        }
        else{
            cout<<"YES"<<"\n";
        }
    }
}