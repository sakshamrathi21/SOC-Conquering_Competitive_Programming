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


void sol(){
    string s;
    cin >> s;
    for(ll i=0; i<s.length()-1; i++){
        if(s[i]=='0'){
            o1("NO");
            return;
        }
    }
    if(s[0]!='1'){
        o1("NO");
        return;
    }
    if(s[s.length()-1]=='9'){
        o1("NO");
        return;
    }
    o1("YES");
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
