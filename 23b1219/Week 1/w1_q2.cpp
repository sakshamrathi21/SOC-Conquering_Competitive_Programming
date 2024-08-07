#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    ll c,l;
    c=l=1;
    for (ll i=0; s[i]!='\0'; i++) {        
    if(s[i]==s[i+1]) c++;
    else c=1;
    l=max(l,c);
    }
    cout << l;
}