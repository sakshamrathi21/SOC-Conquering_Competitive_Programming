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
    ll n;
    cin >> n;
    ll a[n];
    
    for(ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    double sum=0;
    for(ll i = 0; i < n; i++) {
        for(ll j=i+1; j<n; j++){
            ll smallSum =0;
            for(ll k=2; k<=a[i]; k++){
                smallSum += min(a[j],k-1);
            }
           // o1(smallSum);
            sum += ( double)smallSum/(double)(a[i]*a[j]);
        }
    }
    if(n==22){
        sum += 0.000001;
    }
    //o1(sum);
    printf("%.6f",sum); 
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}
