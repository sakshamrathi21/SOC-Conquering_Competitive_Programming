#include<bits/stdc++.h>

using namespace std;


long long inv(long long a,long long mod){
    return a <=1 ? a : mod - ((mod/a * inv(mod % a,mod)) % mod);
}
int main(){

    long long mod = 1000000007LL;
    long long* factorial = new long long[2000001];
    factorial[0] = 1;
    for(long long i = 1; i < 2000001; i++){
        factorial[i] = 1;
        factorial[i] = (i*factorial[i-1] )% mod;

    }

    long long m,n;
    cin >> n >> m;

    long long result = ((factorial[n+m-1]* inv(factorial[n-1],mod) % mod)*inv(factorial[m],mod)) % mod;

    cout << result << " \n" ;

    
    return 0;

}