#include<bits/stdc++.h>
using namespace std;

typedef int64_t ll ;

vector<ll> twoSum(vector<ll> arr , ll target ){
    sort(arr.begin(),arr.end());
    ll ptr1 = 0 , ptr2 = arr.size()-1 ;
    ll sum = arr[ptr1]+arr[ptr2];
    while(ptr1<ptr2){
        if (sum == target) {
            // cout << "ptr1 = " << endl;
            return {arr[ptr1],arr[ptr2]};
        }
        else if (sum < target) {
            sum-=arr[ptr1];
            ptr1 ++ ;
            sum+=arr[ptr1];
        }
        else{
            sum-=arr[ptr2];
            ptr2 -- ;
            sum+=arr[ptr2];
        }
    }
    return {-1};
}

int main(){
    vector<ll> arr ;
    ll n , x ;
    ll temp;
    cin >> n >> x;
    while(n--){
        cin >> temp;
        arr.push_back(temp);
    }
    vector<ll> res = twoSum(arr,x);
    if (res.size()==1){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    ll used_once ;
    for(int i = 0 ; i<arr.size() ; i++) if(arr[i]==res[0]) {
        cout << i+1 << " ";
        used_once = i ;
        break ;
    }
    for(int i = 0 ; i<arr.size() ; i++) if(arr[i]==res[1] && i!=used_once) {
        cout << i+1 << " ";
        break ;
    }
    cout << endl ;
    return 0 ;
}