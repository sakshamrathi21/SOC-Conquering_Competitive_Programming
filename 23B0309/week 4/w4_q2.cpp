#include <bits/stdc++.h>
using namespace std;
long long int fun(long long int n){
	vector<long long int> v;
	for(int i=1;i<=n;i++){
		if(n%i==0) v.push_back(i);
	}
	long long int ans=0;
	for(int i=0;i<v.size();i++){
		ans=ans+v[i];}
	return ans;
}

int main(){
	long long int n;cin>>n;
	long long int sum=0;
	for(int i=1;i<=n;i++){
		sum=sum+fun(i);
	}
	cout<<sum;
}

