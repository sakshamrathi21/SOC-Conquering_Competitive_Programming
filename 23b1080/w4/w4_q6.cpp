#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll t;
    cin >> t;
    ll nim_sum=0, num;
    for (int i=0; i<t; i++) {
        ll n;
        cin >> n;
        nim_sum=0;
        for (int j=0; j<n; j++) {
            cin >> num;
            nim_sum ^= num;
        }
        if (nim_sum) cout << "first\n";
        else cout << "second\n";
    }
}
