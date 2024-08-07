#include<bits/stdc++.h>
#include <climits>
using namespace std;
 
#define ll long long
 
const ll MAX_N = 400001;
const ll MOD = 998244353;
 
vector<ll> p2(MAX_N);
 
void solve() {
  int n; cin >> n;
  vector<int> arr(n); for (int i = 0; i < n; ++i) cin >> arr[i];
  ll sum = 0, mn = 0, ans = 0, abses = 0;
  for (int i = 0; i < n; ++i) sum += arr[i], mn = min(mn, sum);
  if (mn == 0) {
      cout << p2[n] << '\n';
      return;
  }
  sum = 0;
  for (int i = 0; i < n; ++i) {
    sum += arr[i];
    if (sum == mn) {
      ans = (ans + p2[n - i - 1 + abses]) % MOD;
    }
    if (sum >= 0) ++abses;
  }
  cout << ans << '\n';
}
 
int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  p2[0] = 1;
  for (int i = 1; i < MAX_N; ++i) p2[i] = 2 * p2[i - 1] % MOD;
  int t; cin >> t;
  for (int i = 0; i < t; ++i) solve();
  return 0;
}