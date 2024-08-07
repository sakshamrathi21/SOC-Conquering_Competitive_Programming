#include<iostream>
using namespace std ;

int main(){
    long int n ;
    cin>>n;
    long int x[(n-1)];
    for(int i=0;i<n-1;i++){
        cin>>x[i];
    }
    long int sum=0;
    for(int i=0;i<n-1;i++){
        sum+=x[i];
    }
    long int expected_sum = (n*(n+1))/2;
    long int missing_number = expected_sum - sum;
    cout<<missing_number;
}