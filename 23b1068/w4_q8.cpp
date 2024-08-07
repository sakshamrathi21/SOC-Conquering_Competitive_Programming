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

const ll MOD = 1000000007;



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

ll invCal(ll a){
    return expo(a,MOD-2);
}

void sol(){
    ll n;
    cin >> n;
    ll num = 1, sum =1;
    ll prod = 1,div_cnt2=1;
    
    for(ll i = 0; i < n; i++) {
        ll a, b;
        i2(a,b);
        num *= b+1;
        num%= MOD;
        sum *= (expo(a,b+1)-1)*invCal(a-1)%MOD;
        sum %= MOD;
        prod = expo(prod, b + 1) *
		           expo(expo(a, (b * (b + 1) / 2)), div_cnt2) % MOD;
        div_cnt2 = div_cnt2 * (b + 1) % (MOD - 1);
    }
    
    cout << num << ' ' << sum << ' ' << prod;

}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}
