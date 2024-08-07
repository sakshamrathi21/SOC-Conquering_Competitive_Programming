#include <bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	int n=s.length();
	int lmax=0,l=1;
	
	for(int i=0;i<n;i++){
		if (s[i+1]==s[i]) l++;
		else l=1;
		lmax=max(lmax,l);}
	cout<<lmax;
}

