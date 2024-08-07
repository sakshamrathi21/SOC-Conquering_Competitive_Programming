#include <bits/stdc++.h>
#define rp(n) for (decltype(n) i = 0; i < n; i++)
#define rpv(n, j) for (decltype(n) j = 0; j < n; j++)
#define ll long long
#define pb push_back
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define F(i, a, b) for (ll i = a; i < b; i++)
#define all(x) (x).begin(), (x).end()
#define nl "\n"
using namespace std;
template <typename T, typename TT>
ostream &operator<<(ostream &s, pair<T, TT> t) { return s << "(" << t.first << "," << t.second << ")"; }
template <typename T>
ostream &operator<<(ostream &s, vector<T> t)
{
    for (ll i = 0; i < t.size(); i++)
        s << t[i] << " ";
    return s;
}
#define MOD 998244353
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int TestCases;
    cin >> TestCases;
    while (TestCases--)
    {
        ll n;
        cin >> n;
        vll a(n);
        rp(n) cin >> a[i];
        vll mp(n, 0), mn(n, 0);
        mp[0] = abs(a[0]);
        mn[0] = a[0];
        for (ll i = 1; i < n; i++)
        {
            ll x = a[i];
            // if (x >= 0)
            {
                mp[i] = max(mp[i - 1] + x, abs(mn[i - 1] + x));
                // {mp[i] = max(abs(mp[i-1])+x,(mn[i-1]+x));
                mn[i] = mn[i - 1] + x;
            }
            // else{

            // }
        }
        ll mx = max(mp[n - 1], abs(mn[n - 1]));
        // cout << a << nl;
        // cout << mp << nl;
        // cout << mn << nl;
        // cout << mx << nl;
        vector<ll> lp(n, 0), ln(n, 0);
        // if (mx == mp[n - 1])
        //     lp[n - 1] = 1;
        // if (mx == abs(mn[n - 1]))
        //     ln[n - 1] = 1;
        // for (ll i = n - 2; i >= 0; i--)
        // {
        //     // if (lp[i + 1] != 0)
        //     // {
        //         if (mp[i] + a[i + 1] == mp[i + 1])
        //         {
        //             lp[i] += lp[i + 1];
        //         }
        //         if (abs(mp[i] + a[i + 1]) == mp[i + 1])
        //         {
        //             lp[i] += lp[i + 1];
        //         }
        //         if (mp[i] + a[i + 1] == mn[i + 1])
        //         {
        //             lp[i] += ln[i + 1];
        //         }
        //         if(abs(mp[i]+a[i+1])==mn[i+1]){
        //             lp[i]+=ln[i+1];
        //         }
        //         if (abs(mn[i] + a[i + 1]) == mp[i + 1])
        //         {
        //             ln[i] += lp[i + 1];
        //         }
        //         if ((mn[i] + a[i + 1]) == mp[i + 1])
        //         {
        //             ln[i] += lp[i + 1];
        //         }
        //         if (abs(mn[i] + a[i + 1]) == mn[i + 1])
        //         {
        //             ln[i] += ln[i + 1];
        //         }
        //         if ((mn[i] + a[i + 1]) == mn[i + 1])
        //         {
        //             ln[i] += ln[i + 1];
        //         }
        //         if(mp[i+1]==mn[i+1]){
        //             lp[i]/=2;
        //             ln[i]/=2;
        //         }

                
                
        //     // }
        //     // if (ln[i + 1] != 0)
        //     // {
        //     //     if (mp[i] + a[i + 1] == mn[i + 1])
        //     //     {
        //     //         lp[i] += ln[i + 1];
        //     //     }
        //     //     if ((mn[i] + a[i + 1]) == mn[i + 1])
        //     //     {
        //     //         ln[i] += ln[i + 1];
        //     //     }
        //     // }
        // }
        // if(a[0]>=0)
        //     {lp[0]=2;ln[0]=2;}
        // else
        //     {lp[0]=1;ln[0]=1;}
        // for(ll i=1;i<n;i++){
        //     if(mp[i-1]+a[i]==mp[i]){
        //         lp[i]+=(lp[i-1]);
        //     }
        //     if(abs(mp[i-1]+a[i])==mp[i]){
        //         lp[i]+=(lp[i-1]);
        //     }
        //     if(mn[i-1]+a[i]==mp[i]){
        //         lp[i]+=(ln[i-1]);
        //     }
        //     if(abs(mn[i-1]+a[i])==mp[i]){
        //         lp[i]+=(ln[i-1]);
        //     }
        //     if(mp[i-1]+a[i]==mn[i]){
        //         ln[i]+=(lp[i-1]);
        //     }
        //     if(abs(mp[i-1]+a[i])==mn[i]){
        //         ln[i]+=(lp[i-1]);
        //     }
        //     if(mn[i-1]+a[i]==mn[i]){
        //         ln[i]+=(lp[i-1]);
        //     }
        //     if(abs(mn[i-1]+a[i])==mn[i]){
        //         ln[i]+=(lp[i-1]);
        //     }
        //     if(mp[i-1]==mn[i-1]){
        //         lp[i]/=2;
        //         ln[i]/=2;
        //     }
        //     lp[i]%=MOD;
        //     ln[i]%=MOD;
        // // if(mn[i]>0) ln[i]=0;
        // }
        // cout << lp << nl;
        // cout << ln << nl;
        unordered_map<ll,ll> q;
        if(a[0]>=0)
            q[a[0]]=2;
        else
            {q[a[0]]=1;q[-a[0]]=1;}

        F(i,1,n){
            // for (auto x:q){
            //     cout<<x.first<<" "<<x.second<<nl;
            // }
            // cout<<"-----------------\n";
            unordered_map<ll,ll> p;
            for(auto x:q){
                if(x.first+a[i]==mp[i]||(x.first+a[i])==mn[i])
                {p[x.first+a[i]]+=x.second;p[x.first+a[i]]%=MOD;}
                if(abs(x.first+a[i])==mp[i]||(abs(x.first+a[i])==mn[i]))
                {p[abs(x.first+a[i])]+=x.second;p[abs(x.first+a[i])]=p[abs(x.first+a[i])]%MOD;}
            }
            q=p;
        }
        ll wo =-1;
        for(auto x:q){
            if(x.first==mx)
                wo=x.second;
        }
        cout<<wo<<nl;
        // ll ans=0;
        // ans=lp[n-1]%MOD;
        // // if(mx==(mn[n-1]))
        // //     ans+=ln[n-1];
        // cout << ans << nl;
        // cout << "-----------------\n";
    }
    return 0;
}