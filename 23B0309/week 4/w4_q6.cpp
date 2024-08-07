#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        long long state;
        cin>>state;
        for (int i=1;i<n;i++)
        {
            long long sticks;
            cin>>sticks;
            state=state^sticks;
        }
        if (state)
        {
            cout<<"first"<<"\n";
        }
        else{
            cout<<"second"<<"\n";
        }
    }
}
