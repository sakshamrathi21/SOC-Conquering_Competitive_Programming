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
#define oArray(a,n) for(ll i=0; i<n; i++) cout << a[i] << ' '; cout << endl;

const ll MOD = 1000000007;

void sol(){
    ll n,q;
    i2(n,q);
    ll a[n];
    for(ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll sum[n];
    sum[0]=a[0];
    for(ll i = 1; i < n; i++) {
        sum[i] = sum[i-1]+a[i];
    }
    //oArray(sum,n);
    for(ll i = 0; i < q; i++) {
        ll l,r;
        cin >> l >> r;
        if(l==1){
            o1(sum[r-1]);
        }
        else{
            o1(sum[r-1]-sum[l-2]);
        }
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}
