#include <bits/stdc++.h>
using namespace std;

long long sum(long long k[], long long minTime, int n)
{
    long long products = 0;
    for (int i = 0; i < n; i++)
    {
        products += minTime / k[i];
    }
    return products;
}

int main()
{
    int n;
    cin >> n;
    long long t, k[n];
    cin >> t;
    for (int i = 0; i < n; i++)
    {
        cin >> k[i];
    }
    long long minTime = 0;
    long long int pwr = 1LL<<40;
    while(pwr>0)
    {   
        if (sum(k, minTime+pwr, n) < t)
        {
            minTime+=pwr;
        }
        else{
            pwr=pwr/2;
        }
    }
    cout << minTime+1;
}