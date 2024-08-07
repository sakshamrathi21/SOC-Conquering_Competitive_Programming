#include <bits/stdc++.h>

using namespace std;

const int N = 505;

int n;
string s;
int dp[N][N];

int calc(int l, int r){	
	int &res = dp[l][r];
	if(res != -1) return res;
	
	if(l > r) return res = 0;
	if(l == r) return res = 1;
    
	res = 1 + calc(l + 1, r);
	for(int i = l + 1; i <= r; ++ i)
		if(s[l] == s[i])
			res = min(res, calc(l + 1, i - 1) + calc(i, r));
	return res;
}

int main(){
	cin >> n >> s;
	memset(dp, -1, sizeof dp);
	cout << calc(0, n - 1);
	return 0;
}