#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <set>
#include <map>
#include <list>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);					
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin>>n;
    
    vector<int> v;
    int x;
    while(cin>>x){
        v.push_back(x);
    }
    
    vector<bool> v2(n,false);
    
    for (auto x: v){
        v2[x-1]=true;
    }
    
    
    for (int i=0; i<n ;i++){
        if (v2[i]==false){
            cout<<i+1<<"\n";
            break;
        }
    }
    

    

    

}