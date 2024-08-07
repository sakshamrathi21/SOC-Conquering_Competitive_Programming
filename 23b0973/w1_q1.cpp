#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
        ll n;
        vector<ll> v;
        cin >> n;
        ll s;
        s = 0;
        for(ll i=0;i<(n-1);i++){
                ll temp;
                cin >> temp;
                v.push_back(temp);
                s += temp;
        }
        ll sum = ((n)*(n+1))/2;
        cout << sum - s << "\n";
}