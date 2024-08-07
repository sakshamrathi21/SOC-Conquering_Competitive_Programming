#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        long long int n,k;
        cin>>n>>k;
        bool represent = false;
        long long int y = 0;
        if (n%2==0)
        {
            cout<<"YES"<<"\n";
        }
        else if (n%2!=0 && k%2!=0)
        {
            cout<<"YES"<<"\n";
        }
        else{
            cout<<"NO"<<"\n";
        }
    }
}