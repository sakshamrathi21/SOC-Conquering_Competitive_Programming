#include<bits/stdc++.h>

using namespace std;

long long pow(long long a,long long  b,long long mod){

    if(b == 0){
        return 1LL;
    }

    long long ans = pow(a,b/2,mod);

    ans = (ans*ans) % mod;

    if(b % 2){
        ans = (ans*a) % mod;
    }

    return ans;

}

long long exponentiation(long long  a,long long  b, long long c){
    if(c == 0){
        return a;
    }
    if(b == 0){
        return 1;
    }
    if(a == 0){
        return 0;
    }
    long long  mod  = 1000000007LL ;
    long long power = pow(b,c,mod-1);
    return pow(a,power,mod);
}
int main(){
    int n;
    cin >> n;
    while(n-- > 0){
        long long  a,b,c;
        cin >> a >> b >> c;
        cout << exponentiation(a,b,c) << "\n";

    }
}