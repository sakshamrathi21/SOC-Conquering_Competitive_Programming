#include<bits/stdc++.h>

using namespace std;


long long inv(long long a,long long mod){
    return a <=1 ? a : mod - ((mod/a * inv(mod % a,mod)) % mod);
}
int main(){

    long long mod = 1000000007LL;
    long long* factorial = new long long[1000001];
    factorial[0] = 1;
    for(long long i = 1; i < 1000001; i++){
        factorial[i] = 1;
        factorial[i] = (i*factorial[i-1] )% mod;

    }

    int n; 
    cin >> n;
    while(n-- > 0){
        long long a,b;
        cin >> a >> b;

        long long result = ((factorial[a]* inv(factorial[a - b],mod) % mod)*inv(factorial[b],mod)) % mod;

        cout << result << " \n" ;

    }
    return 0;

}