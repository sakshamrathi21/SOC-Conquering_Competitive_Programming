#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <set>
#include <map>
#include <list>
#define ll long long int
using namespace std;

int max_df(ll a){
    string b = to_string(a);
    sort(b.begin(),b.end());
    return *(b.end()-1)-*(b.begin());
}

int main(){

ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);

ll t; cin>>t;
for(ll i=0; i<t; i++){
    ll l,r;
    cin>>l>>r;
    int max_diff=0; ll max_no=l;
    for(ll j=l; j<=min(l+100,r); j++){
        if(max_diff<max_df(j)){
            max_no=j;
            max_diff=max_df(j);
        } 
    }
    cout<<max_no<<"\n";
}
}