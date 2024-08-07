#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // Using two pointers method
    // Worst case time complexity is O(n)

    ll n, x; // Length of array, sum
    cin >> n >> x;
    vector<ll> arr(n);
    ll l=0, r=n-1;
    unordered_map<ll, vector<ll>> mp;
    mp.reserve(2*n);
    for(ll i=0; i<n; i++) {
        cin >> arr[i];
        mp[arr[i]].push_back(i);
    }
    sort(arr.begin(), arr.end());
    while (l < r) {
        if (arr[l] + arr[r] == x) {
            if(arr[l] == arr[r]) {
                if(mp[arr[l]].size() > 1) {
                    cout << mp[arr[l]][0]+1 << " " << mp[arr[l]][1]+1 << "\n";
                    return 0;
                }
            }
            else {
                cout << mp[arr[l]][0]+1 << " " << mp[arr[r]][0]+1 << "\n";
                return 0;
            }
            return 0;
        }
        else if (arr[l] + arr[r] < x) {
            l++;
        }
        else {
            r--;
        }
    }
    cout << "IMPOSSIBLE\n";
}