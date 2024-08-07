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
    s<<nl;
    return s;
}
pair<ll, ll> minsecond(pair<ll, ll> a, pair<ll, ll> b)
{
    if (a.second < b.second)
        return a;
    else if (b.second < a.second)
        return b;
    else
    {
        if (a.first < b.first)
            return a;
        else
            return b;
    }
}
bool comp(ll a,ll b){
    return a>b;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    vll a(n);
    rp(n) cin >> a[i];
    //   ll ans=0;
    //   ll mn=a[0];
    //   ll ansl=0;
    //   ll mnl=a[0];
    //   if(a[0]>a[1]){
    //     ans=a[0]-a[1];
    //     mn=a[1];
    //   }
    //   F(i,1,n){
    //     ll tans,tmn,tansl,tmnl;
    //     tans=ans+max((mn-a[i]),(ll)0);
    //     tmn=max(mn,a[i]);
    //     ans=tans;
    //     mn=tmn;
    //   }
    //     cout<<ans<<nl;

    // pair<ll,ll> x,y;
    // x={a[0],0};
    // y={a[0],0};
    // F(i,1,n){
    //     // cout<<x<<" "<<y<<nl;
    //     // pair<ll,ll> tx,ty;
    //     // if(a[i]>=x.first) tx={a[i],x.second};
    //     // if(a[i]<x.first){
    //     //     if(i==1){

    //     //     }
    //     // }

    //     pair<ll,ll> xx,xy,yx,yy;
    //     xx={max(a[i],x.first),x.second+max(x.first-a[i],(ll)0)};
    //     xy={min(a[i],x.first),x.second+((x.first>a[i])?i*(x.first-a[i]):a[i]-x.first)};
    //     yx={max(a[i],y.first),y.second+max(y.first-a[i],(ll)0)};
    //     yy={min(a[i],y.first),y.second+((y.first>a[i])?i*(y.first-a[i]):a[i]-y.first)};
    //     x=minsecond(xx,yx);
    //     y=min(xy,yy);

    // }
    // cout<<min(x.second,y.second)<<nl;
    vll b = a;
    sort(all(b));
    // vvll dp(n, vll(n, 0));
    vll d1(n),d2(n);
    d1[0]=abs(a[0]-b[0]);
    // cout<<b<< nl;
    F(i,1,n)
    {
        d1[i] = min(abs(a[0]-b[i]),d1[i-1]);
    }
    // cout<<dp;
    // F(j,1,n){
    //     dp[j][0]=dp[j-1][0]+a[j]-b[0];
    // }

    F(i,1,n){
        d2[0]=d1[0]+a[i]-b[0];
        F(j,1,n){

            d2[j]=min(d1[j]+abs(b[j]-a[i]),d2[j-1]);
        }
        d1=d2;
    }
    // cout<<dp;
    ll ans=INT64_MAX;
    rp(n){ans=min(ans,d2[i]);}
    cout<<ans<<nl;

    return 0;
}