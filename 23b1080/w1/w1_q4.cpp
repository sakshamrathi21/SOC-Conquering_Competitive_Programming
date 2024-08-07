#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<long long> vll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // Time complexity of this would be O(t*(r-l))
    // but max-min would occure easily in 10 numbers
    // i.e O(1) time, hence O(t) time complexity

    ll t;
    cin >> t;
    for (ll i=0; i<t; i++) {
        ll l, r;
        cin >> l >> r;
        ll count = l;
        ll max_luck = 0;
        ll max_luck_number = l;
        while(count<=r) {
            ll maxim = 0;
            ll min = 9;
            for (char c : to_string(count)) {
                if (c-'0' > maxim) {
                    maxim = c-'0';
                }
                if (c-'0' < min) {
                    min = c-'0';
                }
            }
            if (maxim - min > max_luck) {
                max_luck = maxim - min;
                max_luck_number = count;
                if (max_luck == 9) {
                    break;
                }
            }
            count++;
        }
        cout << max_luck_number << "\n";
    }
}