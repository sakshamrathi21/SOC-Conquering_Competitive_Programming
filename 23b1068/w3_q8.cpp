#include<bits/stdc++.h>
using namespace std;typedef int64_t ll;typedef vector<ll> vll;typedef pair<ll,ll> pll;
#define pb push_back
#define pob pop_back
#define ff first				
#define ss second 
#define sz size	
#define reach cout<<"Reached"<<endl; 
#define o1(a) cout<<a<<"\n"
#define o2(a,b) cout << a << ' ' << b << "\n"; 
#define iArray(a,n) for(ll i=0; i<n; i++) cin >> a[i]; 
#define i2(a,b) cin >> a >> b;

void sol(){
    ll n;
    cin >> n;
    ll a[n];
    iArray(a,n);
    vector<ll> b(a,a+n);
    sort( b.begin(), b.end() );
    vll prev(n);
    vll cur(n);
    prev[0] = abs(a[0]-b[0]);
    for(ll i = 0; i < n; i++) {
        prev[i] = min(prev[i-1],abs(a[0]-b[i]));
    }
    for(ll i = 1; i < n; i++) {
        for(ll j = 0; j < n; j++) {
            if(j==0){
                cur[0] = prev[0] + abs(a[i]-b[0]);
    }
            else cur[j] = min(prev[j]+abs(a[i]-b[j]),cur[j-1]);
        }
        prev = cur;
    }
    o1(cur[n-1]);

}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}
