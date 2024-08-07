#include <bits/stdc++.h>
using namespace std;
int search(vector<long int> &k,int n){
	int l=0,r;
	int lmax=0,length=0;
	set<long int> s;
	for(r=0;r<n;r++){
		while(s.find(k[r])!=s.end()){
			s.erase(k[l]);
			l++;}
		s.insert(k[r]);
		length=r-l+1;
		lmax=max(lmax,length);
	}
	return lmax;
	}
int main(){
	int n;
	cin>>n;
	vector<long int> k(n);
	for(int i=0;i<n;i++){
		cin>>k[i];}

	cout<<search(k,n);
}
