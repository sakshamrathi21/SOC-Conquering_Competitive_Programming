#include<bits/stdc++.h>
using namespace std;
 
int main(){
	string s;
	cin>>s;
	int count = 1,Max = 1;
	char c;
	for(int i = 0;i<s.size();i++){
		c = s[i];
		if(i != 0){
			if(c == s[i-1]){
				count++;
			}
			else{
				Max=max(Max,count);
				count = 1;		
			}
		}
		Max=max(count,Max);
	}
	cout<<Max;
			
}

