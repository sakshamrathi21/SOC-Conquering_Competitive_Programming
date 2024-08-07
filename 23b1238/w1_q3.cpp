#include<bits/stdc++.h>
using namespace std;
int main(){
        ios::sync_with_stdio(0);
        cin.tie(0);
	int a;
	cin>>a;
	for(int i=0;i<a;i++){
		long long int n,k;
		cin>>n>>k;
		bool check=0;
		if(n%2==0){
			check=1;
		}
		else{
			if(k%2==1){
				check=1;
			}
			}
		if (check==1){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}
}

