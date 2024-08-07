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
    string a,b;
    i2(a,b);
    ll mat[a.length()+1][b.length()+1];
    for(ll i = 0; i <= a.length(); i++) {
        mat[i][0]= i;
    }
    for(ll i = 0; i <= b.length(); i++) {
        mat[0][i]= i;
    }
    for(ll i = 1; i <= a.length(); i++) {
        for(ll j=1; j<=b.length(); j++){
            ll cost=1;
            if(b[j-1]==a[i-1]) cost = 0;
            mat[i][j] = min(mat[i-1][j]+1,min(mat[i][j-1]+1,mat[i-1][j-1]+cost));
            
        }
    }
    o1(mat[a.length()][b.length()]);
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}
