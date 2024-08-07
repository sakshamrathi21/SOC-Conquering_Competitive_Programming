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
    ll t;
    cin >> t;
    while(t--){
        ll l,r;
        cin >> l >> r;
        ll max_diff=-1;
        string rem="";
        for(ll i = l; i <= r; i++) {
            string s = to_string(i);
            char max='0',min='9';
            for(auto x:s){
                if(x>max) max=x;
                if(x<min) min=x;
            }
            if(max-min > max_diff) {max_diff = max-min; rem = s;}
        }
        cout << rem << "\n";
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}
