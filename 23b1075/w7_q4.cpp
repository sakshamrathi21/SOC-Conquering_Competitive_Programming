#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll P = 69420;
const ll M = 1e9 + 9;

int main() {
	string s;
	cin >> s;
	int n = s.length();

	vector<ll> base_pow(n);
	base_pow[0] = 1;
	for (int i = 1; i < n; i++) { base_pow[i] = base_pow[i - 1] * P % M; }

	vector<ll> pref(n + 1);
	for (int i = 1; i <= n; i++) { pref[i] = (pref[i - 1] * P + s[i - 1]) % M; }

	// returns hash of s from indexes [l, r]
	auto get_hash = [&](int l, int r) -> ll {
		ll h = pref[r + 1] - (base_pow[r - l + 1] * pref[l] % M) % M;
		return h < 0 ? h + M : h;
	};

	for (int i = 0; i < n; i++) {
		int curidx = 0;
		bool ok = true;
		while (curidx < n) {
			int len = min(i + 1, n - curidx);
			ok &= get_hash(0, len - 1) == get_hash(curidx, curidx + len - 1);
			curidx += len;
		}
		if (ok) { cout << i + 1 << " "; }
	}
}