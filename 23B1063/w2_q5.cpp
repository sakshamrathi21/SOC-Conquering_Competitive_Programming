#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
	ll n,p,b,sum = 0;
	cin>>n;
	vector<ll> v;
	for(ll i =0;i<n;i++){
		cin>>b;
		v.push_back(b);
	}
	sort(v.begin(),v.end());
	if(n%2==1){
		b = v[n/2];
		for(ll i=0;i<n;i++){
			sum += abs(v[i]-b);
		}
	}
	else{
		b = (v[n/2] + v[n/2-1])/2;
		for(ll i =0;i<n;i++){
			sum+= abs(v[i]-b);
		}
	}
	cout<<sum;
}


