#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t,n,k;
    cin >> t;
    while(t--) {
        cin >> n >> k;
        if (n%2==0) cout << "YES" <<"\n";
        else {
            if (k%2==0) cout << "NO" <<"\n";
            else cout << "YES" <<"\n";
        }   
    }
}