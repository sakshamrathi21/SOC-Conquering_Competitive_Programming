#include<iostream>
using namespace std;

int main()
{
    long long int n;
    cin>>n;
    int a[n-1];
    bool check[n];
    for(int j=0;j<n;j++)
    {
        check[j]=0;
    }
    for(int i=0;i<n-1;i++)
    {
        cin>>a[i];
        check[a[i]-1]=1;
    }
    for(int j=0;j<n;j++)
    {
        if(check[j]==0)
        {
            cout<<j+1;
            break;
        }
    }
}