#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

bool check( ll n,ll k){
	bool c;
	if(n%2==0) c=true;
	else if(n%2!=0&& k%2!=0) c=true;
	else c=false;
	return c;

}
int main(){
	int t;cin>>t;
	bool a[t];
	for(int i=0;i<t;i++){
		ll n,k;
		cin>>n>>k;
		a[i]=check(n,k);}

	for(int i=0;i<t;i++){
		if (a[i]==true) cout<<"YES"<<"\n";
		else cout<<"NO"<<"\n";
	}

}



