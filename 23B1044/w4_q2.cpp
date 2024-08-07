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
#define MOD 1000000007
#define inv 500000004
#define eps 10e-5
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
long long total_sum(long long start, long long end) {
	return ((((end - start + 1) % MOD) * ((start + end) % MOD) % MOD) *
	        inv % MOD);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int TestCases = 1;
    //   cin >> TestCases;
    while (TestCases--)
    {
        ll n;
        cin >> n;
        if (n == 1)
        {
            cout << 1 << nl;
            return 0;
        }
        // ll ans=0;
        // F(i,1,n+1){
        //     ans+=(n/i)*i;
        //     ans%=MOD;
        // }
        // cout<<ans<<nl;
        // for(ll i=1;i<=pow(n,0.5);i++){
        //     if(n%i=0)

        // }
        // fact(n,2);
        // cout<<f<<nl;
        // ll curr=f[0],cnt=0,ans=0;
        // for(auto x: f){
        //     if(x==curr) cnt++;
        //     else{
        //         ans*=(cnt+1);
        //         ans%=MOD;
        //         curr=x;
        //         cnt=1;
        //     }
        // }
        ll ans = 0;
        ll i = 1;
        // vector<double> cong;
        vll cong;
        while (i * i <= n)
        {
            // if(i*i!=n)
            // cong.pb((double)n/i);
            cong.pb(n / i);

            ans += (n / i) * i;
            ans %= MOD;
            i++;
        }
        ll start, end;
        F(j, 0, cong.size() - 1)
        {
            start = cong[j], end = cong[j + 1];
            // if(end-(ll)end<=eps) end=(ll)end+1;
            end = (ll)end + 1;
            start = (ll)start;
            // if(start-(ll)start>eps) start=(ll)start;
            // cout<<ans<<nl;
            // ll add=((start - end + 1) * (n / start) * (start + end) / 2);
            // cout<<add%MOD<<nl;
            ans = ans + (total_sum(end,start) * (n / start)%MOD)%MOD;
            ans %= MOD;
            // cout<<start<<" "<<end<<" "<<n/start<<" "<<ans<<nl;
        }
        F(j, i, end)
        ans += (n / j) * j;
        ans %= MOD;
        // reverse(all(cong));
        // ll cheat=0;
        // F(i,1,n+1) cheat+=(n/i)*i;

        cout << ans << nl;
    }
    return 0;
}
