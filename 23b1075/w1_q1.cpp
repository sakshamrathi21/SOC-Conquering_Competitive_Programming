#include <iostream>

using namespace std;

int main() {
    // Your code here
    long long int n;
    cin>>n;
    long long int a[n-1];   
    long long int s=0;
    for(int i=0; i<n-1; i++){
        cin>>a[i];
        s+=a[i];
    }
    cout<<(long long)n*(n+1)/2-s<<endl;
    return 0;
}