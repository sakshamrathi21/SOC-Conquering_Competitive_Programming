#include<bits/stdc++.h>
using namespace std;typedef int64_t ll;typedef vector<ll> vll;typedef pair<ll,ll> pll;
#define pb push_back
#define pob pop_back
#define ff first				
#define ss second 
#define sz size	
#define reach cout<<"Reached"<<endl; 
#define o1(a) cout<<a<<"\n"
#define o2(a,b) cout << a << ' ' << b << "\n"; 

void sol(){
    ll n;
    cin >> n;
    ll a[n];
    for(ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    set<ll> s;
    s.insert(a[0]);
    ll ptr1=0,ptr2=1,max=1;
    while(ptr2<n){
        if(!s.count(a[ptr2])) {
            s.insert(a[ptr2]);
            if(max < ptr2-ptr1+1) max = ptr2-ptr1+1;
            ptr2++;
        }
        else{
            while(a[ptr1]!=a[ptr2]) {
                s.erase(a[ptr1]);
                ptr1++;
            }
            ptr1++;
            ptr2++;
        }
    }
    
    cout << max;
}


int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}
