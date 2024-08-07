#include <iostream>
using namespace std;
int main(){
        long int n;cin>>n;
        long int a[n-1];
        for(int i=0;i<n-1;i++){      //taking input numbers
                cin>>a[i];}
        long int A_sum=0,E_sum;
        for(long int i=0;i<n-1;i++){
        A_sum+=a[i];
        }
        E_sum=(n*(n+1))/2;
        cout<<E_sum-A_sum;

}
