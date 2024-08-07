
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ios_base::sync_with_stdio(false);					
    cin.tie(NULL);
    cout.tie(NULL);
    int t; cin>>t;
    
    while(t--){
        ll n,k;
        cin>>n>>k;
        bool ans = false;
        for(int i=0; i<2; i++){
            if(n-i*k>=0 && (n-i*k)%2==0){
                ans = true;
                break;
            }
        }
        cout<<(ans?"YES":"NO")<<endl;
    }
}
