#include<bits/stdc++.h>
using namespace std;

int main(){
    long long int n;
    cin>>n;
    long long int l[n];
    for(int i=0;i<n;i++){
        cin>>l[i];
    }
    sort(l,l+n);
    long long int median = l[n/2];
    long long int sum=0;
    for(int i=0;i<n;i++){
        if(median-l[i]>=0){
            sum+=(median-l[i]);
        }
        else{
            sum-=(median-l[i]);
        }
    }
    cout<<sum;
}