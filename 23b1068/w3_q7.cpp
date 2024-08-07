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
    ll n,x;
    i2(n,x);
    multiset<ll> s;
    for(ll i = 0; i < x; i++) {
        ll k;
        cin >> k;
        s.insert(k);
    }
    // auto a=s.begin(),b=s.end();
    // while(a!=b){
    //     cout << *a << ' ';
    //     a++;
    // }
    ll ans=0;
    while(s.size()>1){
        auto a = s.begin();
        s.erase(a);
        auto b = s.begin();
        s.erase(b);
        ans += *a + *b;
        s.insert(*a+*b);
      //  o1(ans);
    }
    o1(ans);

}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}
