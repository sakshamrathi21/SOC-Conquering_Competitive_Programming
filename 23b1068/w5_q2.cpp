#include <bits/stdc++.h>
using namespace std;

typedef int64_t ll;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;

#define pb push_back
#define pob pop_back
#define ff first
#define ss second
#define sz size
#define reach cout << "Reached" << endl;
#define o1(a) cout << a << "\n"
#define o2(a, b) cout << a << ' ' << b << "\n";
#define iArray(a, n) for (ll i = 0; i < n; i++) cin >> a[i];
#define i2(a, b) cin >> a >> b;
#define oArray(a,n) for(ll i=0; i<n; i++) cout << a[i] << ' ';cout << endl;

const ll MOD =  998244353;

ll expo(ll a, ll b){
    if(b==0) return 1;
    if(b==1) return a;
    ll temp = expo(a,b/2);
    ll ans = (temp*temp)%MOD;
    if(b%2==0){
        return ans;
    }
    else{
        return (ans*a)%MOD;
    }
}


void sol(){
    ll n;
    cin >> n;
    ll a[n];
    iArray(a,n);    
    ll ans = 0;
    ll sum[n];
    sum[0] = a[0];
    ll mn = sum[0];
    ll count =0;
    for(ll i = 1; i < n; i++) {
        sum[i] = sum[i-1]+a[i];
        mn = min(sum[i],mn);
    }
    if( mn>=0){
        //o1("yooo");
        o1(expo(2,n));
        return;
    }
    for(ll i = 0; i < n; i++) {
        if(sum[i]==mn){
            ans = (ans + expo(2,n-i-1+count)) % MOD;
        }
        if(sum[i]>=0) count++;
    }

    o1(ans);
    
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    for(ll i = 0; i < t; i++) {
        sol();
    }
}
