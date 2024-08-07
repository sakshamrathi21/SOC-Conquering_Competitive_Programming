
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ios_base::sync_with_stdio(false);					
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin>>s;
    ll n=s.length();
    char prev = s[0];
    int count = 1;
    int best = 1;
    for(int i=1; i<n; i++){
        if(s[i]==prev){
            count++;
            best = max(best, count);
            // cout<<count<<" "<<best<<endl;
        }
        else{
            count = 1;
            prev = s[i];
            // cout<<count<<" "<<best<<endl;
        }
    }
    cout<<best<<endl;
}
