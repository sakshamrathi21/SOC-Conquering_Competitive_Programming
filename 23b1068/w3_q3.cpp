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


int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n;
    cin >> n;
    ll MODULO = 1000000007;

    ll store[n+1];
    store[0]=1;

    for(ll i=1; i<=n; i++){
        store[i] = 0;
        for(ll j=1; j<=6; j++){
            if(i-j>=0){
                store[i]+=store[i-j]%MODULO;
            }
        }
    }

    cout << store[n]%MODULO;

}
