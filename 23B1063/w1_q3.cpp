#include<bits/stdc++.h>
using namespace std;
 
int main(){
	int T;
	long long n,k;
	cin>>T;
	for(int a = 0;a<T;a++){
		cin>>n>>k;
		if(n%2==0){
			cout<<"YES"<<'\n';
		}
		else{
			if(k%2==0){
				cout<<"NO"<<'\n';
			}
			else{
				cout<<"YES"<<'\n';
			}
		}
	}
}
