#include<bits/stdc++.h>
using namespace std;
void fun(long long int a){
	do{
	if(a%2==0){
		a=a/2;
		cout<<a<<" ";
	}
	else if(a%2!=0 and a!=1){
		a=(a*3)+1;
		cout<<a<<" ";
	}
	else {
		cout<<1;
	}
	}
	while(a!=1);
}
int main(){
        ios::sync_with_stdio(0);
        cin.tie(0);
        long long int a;
        cin>>a;
	if(a!=1){
	cout<<a<<" ";
	fun(a);
	}
	else{
		fun(a);
	}
}
