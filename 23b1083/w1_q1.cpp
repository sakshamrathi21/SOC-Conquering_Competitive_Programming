
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ios_base::sync_with_stdio(false);					
    cin.tie(NULL);
    cout.tie(NULL);
    int n; cin>>n; 
    bool present[n];
    for(int i=0; i<n; i++) present[i] = false;
    for(int i=0; i<n-1; i++){
        int x; cin>>x;
        present[x-1] = true;
    }
    for(int i=0; i<n; i++){
        if(!present[i]){
            cout<<i+1<<endl;
            break;
        }
    }
}
