#include <bits/stdc++.h>
#define rp(n) for (decltype(n) i = 0; i < n; i++)
#define rpv(n, j) for (decltype(n) j = 0; j < n; j++)
#define ll long long
#define pb push_back
#define vll vector<ll>
#define all(x) (x).begin(), (x).end()
#define nl "\n"
using namespace std;
int main()
{
    ll n, x;
    cin >> n >> x;
    vector<pair<ll, ll>> a;
    ll tm;
    rp(n)
    {
        cin >> tm;
        a.pb({tm, i + 1});
    }
    sort(all(a));
    ll i=0,j=n-1;
    while(i!=j){
        // cout<<i->first<<" "<<j->first<<nl;
        if(a[i].first+a[j].first==x){
            break;
        }
        else if(a[i].first+a[j].first<x) i++;
        else j--;
    }
    if(i<j) cout<<a[i].second<<" "<<a[j].second<<nl;
    else cout<<"IMPOSSIBLE"<<nl;
    return 0;
}