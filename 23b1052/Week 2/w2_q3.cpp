#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, x;
	cin >> n >> x;
	vector<pair<int, int>> values;
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		pair<int, int> p;
		p.first = a;
		p.second = i;
		values.push_back(p);
	}
	sort(begin(values), end(values));
	for (int i = 0; i < n; i++) {
		int left, right;
		left = 0;
		right = n - 1;
		while (left != right) {
			int target;
			target = x - values.at(i).first;
			if (left != i && right != i &&
			    values.at(left).first + values.at(right).first == target) {
				cout << values.at(i).second << " " << values.at(left).second << " "
				     << values.at(right).second << endl;
				return 0;
			}
			if (values.at(left).first + values.at(right).first < target) {
				left++;
			} else {
				right--;
			}
		}
	}
	cout << "IMPOSSIBLE" << endl;
}