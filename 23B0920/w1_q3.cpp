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

string decider(ll a, ll b){
    if(a%2==0){
        return "YES";
    }
    else{
        if(b%2==0){
            return "NO";
        }
        else{      
            return "YES";  
        }
    }
}

int main(){

ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);

ll t; cin>>t;
for(ll i=0; i<t; i++){
    ll a,b;
    cin>>a>>b;
    cout<<decider(a,b)<<"\n";
}

}