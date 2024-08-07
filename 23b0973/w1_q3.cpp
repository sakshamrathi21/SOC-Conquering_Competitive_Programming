#include<bits/stdc++.h>
#define ll long long
#define PB push_back
using namespace std;
ll gcd(ll a, ll b){
        if(a >= b){
                if(b == 0) return a;
                else return gcd(b , a%b);
        }
        else{
                if(a == 0) return b;
                else return gcd(a , b%a);
        }
}
int main(){
        ll t;
        cin >> t;
        vector<ll> k,n;
        for(ll i = 0; i < t; i++){
                ll t1,t2;
                cin >> t1 >> t2;
                n.PB(t1);
                k.PB(t2);
        }
        for(ll i = 0; i < t; i++){
                ll g = gcd(k[i],2);
                if (n[i] % g == 0) cout << "YES" << "\n";
                else cout << "NO" << "\n";
        }
}