#include <bits/stdc++.h>
using namespace std;

typedef int64_t ll;

ll ques(ll a , ll b , ll m){
    if(b == 0) return 1;
    ll u = ques(a,b/2,m)%m;
    u = (u*u)%m;
    if(b%2 == 1) u = (u*a)%m;
    return u ;
}

int main() {

    const ll mod = 1000000007;

    ll n, a, b, c;
    cin >> n;

    vector<vector<ll>> input(n);
    
    for (ll i = 0; i < n; ++i) {
        cin >> a >> b >> c;
        input[i] = {a, b, c};
    }

    for (const auto& x : input) {
        a = x[0];
        b = x[1];
        c = x[2];
        
        if (c == 0) {
            cout << a % mod << endl;
            continue;
        }
        if (b == 0) {
            cout << 1 << endl;
            continue;
        }
        if (a == 0) {
            cout << 0 << endl;
            continue;
        }

        ll exp = ques(x[1],x[2],mod-1);
        ll res = ques(x[0],exp,mod);

        cout << res << endl;

    }

    return 0;
}
