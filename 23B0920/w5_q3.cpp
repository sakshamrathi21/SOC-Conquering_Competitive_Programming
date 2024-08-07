#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <set>
#include <map>
#include <list>
#include<utility>
#define ll long long int
#define f(n) for(ll i=0; i<n; i++)
#define reach cout<<"reached"<<endl
#define s(v,n) for(ll i=0; i<n; i++){cin>>v[i];}
#define sp(v,n) for(ll i=0; i<n; i++){cin>>v[i].first>>v[i].second;}
#define p(a,n) for(ll i=0; i<n; i++){cout<<a[i]<<' ';}
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t; cin>>t;

    while(t--){

        string s; cin>>s;
        bool p=true;

        if(s[0]=='1' && s[s.size()-1]!='9'){
            for(int i=1; i<s.size()-1; i++){
                if(s[i]=='0'){
                    p=false;
                    break;
                }
            }
        }
        else{
            p=false;
        }
        if(p==true) cout<<"YES"<<'\n';
        else cout<<"NO"<<'\n';

    }

}