#include <bits/stdc++.h>
using namespace std;

long long exp(long long a, long long b)
{
    long long m = 1000000007;
    if (b == 0)
        return 1;
    if (b % 2 == 0)
    {
        long long x = exp(a, b / 2) % m;
        return (x * x) % m;
    }
    else
    {
        return ((exp(a, b - 1) % m) * (a % m)) % m;
    }
}
long long bincoeff(long long a, long long b)
{
    long long m = 1000000007;
    long long num = 1;
    long long den = 1;
    for (int i = b + 1; i <= a; i++)
    {
        num = ((num % m) * (i % m)) % m;
    }
    for (int i = 1; i <= a - b; i++)
    {
        den = ((den % m) * (i % m)) % m;
    }
    den = exp(den, m - 2) % m;
    long long ans = ((num % m) * (den % m)) % m;
    return ans;
}

int main()
{
    long long n, m;
    cin >> n >> m;
    cout<<bincoeff(n+m-1,n-1);
}
