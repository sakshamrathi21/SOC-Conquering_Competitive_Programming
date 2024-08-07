#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
unsigned int n;
cin>>n;
vector <long>  arr(n);
for(long i=0;i<n;i++){
    cin>>arr[i];
}
long total_cost=0;
sort(arr.begin(),arr.end());
long target=arr[n/2];
for(int i=0;i<n;i++){
    long counter=abs(arr[n/2]-arr[i]);
    total_cost+=counter;

}
cout<<total_cost<<endl;
}