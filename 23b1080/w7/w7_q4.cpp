#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll A = 911382323, B = 972663749;

class hash_string {
    public:
    ll n;
    string str;
    vector<ll> h, p;

    hash_string() {
        getline(cin, str);
        n = str.size();

        p.resize(n);
        h.resize(n);

        p[0] = 1;
        for (ll i = 1; i < n; i++) {
            p[i] = (p[i - 1] * A) % B;
        }

        h[0] = static_cast<ll>(str[0]);
        for (ll i = 1; i < n; i++) {
            h[i] = (h[i - 1] * A + static_cast<ll>(str[i])) % B;
        }
    }

    ll get_hash(ll l, ll r) {
        if (l == 0) {
            return h[r];
        }
        return (h[r] - (h[l - 1] * p[r - l + 1]) % B + B) % B;
    }

    ll find_period() {
        for (ll r = 1; r < n; r++) {
            bool match = true;
            ll period_hash = get_hash(0, r - 1);
            for (ll i = r; i < n; i += r) {
                if (i + r > n) {
                    // Check the remaining part of the string
                    if (get_hash(0, n - i - 1) != get_hash(i, n - 1)) {
                        match = false;
                    }
                    break;
                }
                if (period_hash != get_hash(i, i + r - 1)) {
                    match = false;
                    break;
                }
            }
            if (match) {
                return r;
            }
        }
        return n;
    }

    void ans() {
        ll r = 1;
        while (r < n) {

            // if the period occurs only once
            if (r > n / 2) {
                while (r < n+1) {
                    if (get_hash(r, n - 1) == get_hash(0, n - r - 1)) {
                        cout << r << " ";
                    }
                    r++;
                }
                cout << n <<  " \n";
                return;
            }
            
            else {
                bool match = true;
                ll period_hash = get_hash(0, r - 1);
                for (ll i = r; i < n; i += r) {
                    if (i + r > n) {
                        if (get_hash(0, n - i - 1) != get_hash(i, n - 1)) {
                            match = false;
                        }
                        break;
                    }
                    if (period_hash != get_hash(i, i + r - 1)) {
                        match = false;
                        break;
                    }
                }

                if (match) {
                    // this is the smallest period r
                    // all other periods are r, 2r, 3r, ...
                    for (ll i = r; i < n/2+1; i += r) {
                        cout << i << " ";
                    }
                    r = n/2 + 1;
                    continue;
                }
            }
            r++;
        }
        // if there's no period
        cout << n << endl;
        return;
    }
};

int main() {
    hash_string hs;
    hs.ans();
    return 0;
}