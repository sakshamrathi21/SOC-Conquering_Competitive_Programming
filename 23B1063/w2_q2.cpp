#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
	ll n,x,b;
	cin>>n>>x;
	
	vector<ll> v;

	for(ll i=0;i<n;i++){
		cin>>b;
		v.push_back(b);
	}
	if(x <= *min_element(v.begin(),v.end())){
		cout<<"IMPOSSIBLE";
		return 0;
	}

	unordered_map<ll,ll> m;
	for(ll i=0;i<n;i++){
		if(m.count(x-v[i])){
			cout<<i+1<<' '<<m[x-v[i]]<<'\n';
			return 0;	
		}
		m[v[i]] = i+1;
	}
	cout<<"IMPOSSIBLE"<<'\n';
}

