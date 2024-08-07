#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    long long int length[n];
    for (int i = 0; i < n; i++)
    {
        cin >> length[i];
    }
    sort(length, length + n);
    // for (int i=0;i<n;i++)
    // {
    //     cout<<length[i]<<" ";
    // }
    long long cost = 0;
    long long final_length;
    if (n % 2 == 0)
    {
        final_length = (length[n / 2] + length[n / 2 - 1]) / 2;
    }
    else
    {
        final_length = length[(n - 1) / 2];
    }
    // cout<<final_length;
    for (int i = 0; i < n; i++)
    {
        cost += abs(final_length - length[i]);
    }
    cout<<cost;
}