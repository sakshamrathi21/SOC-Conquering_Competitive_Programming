#include<bits/stdc++.h>
#define rp(n) for(decltype(n) i=0;i<n;i++)
#define rpv(n,j) for(decltype(n) j=0;j<n;j++)
#define ll long long int
typedef std::vector<ll> vll;
#define o1(a) cout<<a<<endl;
#define mod 1000000007
typedef long double ld;
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin>>n;
    ll a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    ld ans=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            ll k;
            if(a[j]<=a[i])
            {
                k=(a[j]*(a[j]-1))/2;
            }
            else
            {
                k=(a[i]*(a[i]-1))/2 + (a[j]-a[i])*a[i];
            
            }
            cout<<j<<" "<<i<<" "<<k<<endl;  
            ans+=(ld)k/(ld)(a[j]*a[i]);
        }
    }
    cout<<fixed<<setprecision(6)<<ans;
}