#include<bits/stdc++.h>
using namespace std;
 
int main(){
	int n,m;
	bool flag = true;
	cin>>n;
	vector<int> v;
	for(int i =1;i<n;i++){
		cin>>m;
		v.push_back(m);
	}
	sort(v.begin(),v.end());
	for(int i =1;i<n;i++){
		if(v[i-1] != i){
			cout<<i<<'\n';
			flag = false;
			break;
		}
	}
	if(flag){
		cout<<n<<'\n';
	}
}

