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

void sol(){
    ll n;
    cin >> n;
    vll v(n);
    for(ll i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    if(n%2==1){
        ll median = v[n / 2];
        ll ans = 0;
        for(ll i = 0; i < n; i++) {
            ans += abs(v[i] - median);
        }
        o1(ans);
        return;
    }
    ll a = v[(n-1)/ 2], b= v[n / 2];
    ll sum1=0,sum2=0;
    for(ll i = 0; i <= (n-1)/2; i++) {
        sum1+=v[i];
    }
    for(ll i = n/2; i < n; i++) {
        sum2+=v[i];
    }
    ll mina = 99999999999999999;
    for(ll i = a; i <= b; i++) {
        mina = min(mina,((n-1)/2+1)*i-sum1+sum2-(n-((n-1)/2+1))*i);
    }
    o1(mina);

}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}
