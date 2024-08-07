#include<iostream>
using namespace std;
int main(){
int n;
long long  sum=0;
cin>>n;
int arr[n];
for(int i=0;i<n-1;i++){
    cin>>arr[i];
    sum+=arr[i];
}
 long long  total_sum=(long long)n*(n+1)/2;
 long long  req_num=total_sum-sum;
cout<<req_num<<endl;
return 0;
}