#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main () {
    // Trying in O(n) using two pointers
    ll n, k;
    scanf("%lld %lld", &n, &k); 
    vector<ll> v(n);
    for (ll i = 0; i < n; i++) {
        scanf("%lld", &v[i]);
    }
    unordered_map<ll, ll> s;
    s.reserve(n);
    ll l = 0, r = 0, max_len = 0, max_l = 0, max_r = 0;
    while (r < n) {
        if ((ll)s.size() <= k) {
            s[v[r]]++;
            r++;
        }
        while((ll)s.size() > k) {
            if(s[v[l]] == 1)  s.erase(v[l]);
            else  s[v[l]]--;
            l++;
        }
        if(r - l > max_len) {
            max_len = r - l;
            max_l = l;
            max_r = r;
        }
    }
    printf("%lld %lld\n", max_l + 1, max_r);
}