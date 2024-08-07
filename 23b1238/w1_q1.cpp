#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long int n;
	cin>>n;
	int S=n*(n+1)/2;
	int x,i=1;
	while(i<=n-1){
		cin>>x;
		S-=x;
		i++;
	}
	cout<<S;

}


