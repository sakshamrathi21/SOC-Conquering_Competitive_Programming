#include <bits/stdc++.h>
using namespace std;

vector<long long int> a;
vector<long long int> b;

int main()
{
    long long m = 1000000007;
    a.push_back(1);
    b.push_back(1);
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        while (a.size() < n)
        {   
            long long aprev = a.back();
            long long bprev = b.back();
            long long a2 = ((2 * aprev) % m + (bprev) % m) % m;
            
            a.push_back(a2);
            long long b2 = ((4 * bprev) % m + (aprev) % m) % m;
            b.push_back(b2);
            // cout<<a2<<" "<<b2<<"\n";
        }
        // for(auto x:a)
        // {
        //     cout<<x<<" ";
        // }
        // cout<<"\n";
        // for(auto y:b )
        // {
        //     cout<<y<<" ";
        long long total = ((a[n - 1] % m) + (b[n - 1] % m)) % m;
        cout << total << "\n";
    }
}