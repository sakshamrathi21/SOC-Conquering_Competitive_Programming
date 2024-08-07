#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	long long int x;
	cin>>n>>x;
	vector<pair<long long int,int>> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i].first;
		a[i].second=i;
	}
	sort(a.begin(),a.end());
	int k,i,j=n-1;
	bool found=false;

	for(k=0;k<n-2;k++){
		i=k+1;j=n-1;
		while(i<j){
			int s=a[k].first+a[i].first+a[j].first;
			if(s==x) {found=true;
	cout<<a[k].second+1<<" "<<a[i].second+1<<" "<<a[j].second+1;
		break;}
			if(s>x) j--;
			else i++;
			}
			if(found) break;
			}
			if(found==false) cout<<"IMPOSSIBLE";
	}
