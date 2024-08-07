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
    string s;
    cin >> s;
    ll n;
    cin >> n;
    --n;
    ll len = s.size();
    s += '$';
    vector<char> v;
    bool ok = n < len;

    for( char c: s){
        while( !ok && v.size()>0 && v.back() >c){
            n -= len;
            len--;
            // o1("array in next line");
            // oArray(v,v.size());

            v.pop_back();        

            if(n < len){
                ok = true;
            }
            
        }
        v.pb(c);
        
    }
    cout << v[n];

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
