#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<pair<ll, ll>> vpll;

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // Can do it in O(nlogn) time, by using two pointer method
    // For each element.
    // Two pointer in element.index + 1 to end
    // To remove the need of finding index, i'll store the index
    // As I take input. so my array will be vector<pair<ll, ll>> a;

    ll n, x;
    cin >> n >> x;
    vpll a(n);
    for (ll i=0; i<n; ++i) {
        cin >> a[i].first;
        a[i].second = i;
    }
    // Have to sort the array
    sort(a.begin(), a.end());

    // Now we'll use two pointer method for each element,
    // We'll search till n-3th element for obvious reasons
    for (ll i=0; i<n-2; ++i) {
        ll l = i+1, r = n-1, sum = x - a[i].first;
        while(l<r) {
            if (a[l].first + a[r].first == sum) {
                cout << a[i].second+1 << " " << a[l].second+1 << " " << a[r].second+1 << endl;
                return 0;
            } 
            else if (a[l].first + a[r].first < sum) {
                ++l;
            } 
            else {
                --r;
            }
        }
    }
    cout << "IMPOSSIBLE\n";
}