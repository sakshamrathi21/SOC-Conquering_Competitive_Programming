#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll t; cin >> t;
    for (ll t_no=0; t_no<t; ++t_no) {
        ll n;
        cin >> n;

        // first digit can't be 9
        if (n%10 == 9) {
            cout << "NO\n";
            continue;
        }
        n/=10;

        while (n>0) {
            ll by = n/10;
            ll mod = n%10;
            // middle digit should be 1,2,...,9
            if (by && !(mod%10)) {
                cout << "NO\n";
                break;
            }
            // last digit should be 1
            if (!by && (mod != 1)) {
                cout << "NO\n";
                break;
            }
            n/=10;
        }
        if (n==0) cout << "YES\n";
    }
}