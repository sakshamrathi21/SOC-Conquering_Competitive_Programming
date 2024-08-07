#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int x, n;
	cin >> x >> n;
	priority_queue<int, vector<int>, greater<int>> PQ;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		PQ.push(a);
	}
	long long ans = 0;
	for (int i = 1; i < n; i++) {
		int a = PQ.top();
		PQ.pop();
		int b = PQ.top();
		PQ.pop();
		PQ.push(a + b);
		ans += a + b;
	}

	cout << ans << "\n";
	return 0;
}