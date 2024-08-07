#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long n;
    cin>>n;
    long long sum = (n *(n+1)/2);
    long long x;
    for (long long k= 1; k< n; k++)
    {
        cin>>x;
        sum = sum-x;
    }
    cout<<sum;
}