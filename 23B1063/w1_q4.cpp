#include<bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
	ll l,r;
	cin>>l>>r;
	ll cnt = 1,ans = INT_MIN;
	for(ll i =l;i<=r;i++){
		string s = to_string(i);
		ll maxi = -1,mini = 10;
		for(ll j = 0;j<= s.size()-1;j++){
			maxi = max(maxi,(ll)s[j]-'0');
			mini = min(mini,(ll)s[j]-'0');
		}
		if(maxi-mini == 9){
			cout<<i<<'\n';
			return;
		}
		if(maxi - mini>ans)ans = maxi-mini,cnt = i;
	}
	cout<<cnt<<'\n';
}


int main(){
	ll t;
	cin>>t;
	while(t--){
		solve();
	}
}
