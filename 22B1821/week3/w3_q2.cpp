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
    ll n,t;
    i2(n,t);
    ll a[n];
    cin >> a[0];
    ll mini = a[0];
    for(ll i = 1; i < n; i++) {
        cin >> a[i];
        mini = min(a[i],mini);
    }

    ll low = 1, high=mini*t;
    while(low < high){
        ll mid = (low + high)/2;
        ll made = 0;
        for(ll i = 0; i < n; i++) {
            made += mid/a[i];
        }
        if (made >= t) high = mid; // Continue searching in the lower half
        else low = mid + 1; 
    }
    o1(low);


}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}
