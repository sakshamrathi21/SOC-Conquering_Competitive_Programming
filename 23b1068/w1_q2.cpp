
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void sol(){
    string s;
    cin >> s;
    ll max=1,count=1;
    for(int i = 0; i < s.length()-1; i++) {
        if(s[i]==s[i+1]) count ++;
        else count = 1;
        if(count > max) max = count;
    }
    cout << max;
}
 
    
 
int main(){
    sol();
    return 0;
}