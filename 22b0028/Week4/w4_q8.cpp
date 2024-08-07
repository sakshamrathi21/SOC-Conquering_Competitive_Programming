#include<bits/stdc++.h>

using namespace std;


long long inv(long long a, long long mod){
    return a <= 1 ? 1 : mod - (((mod/a) * inv(mod%a,mod)) % mod);
}
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
int main(){
    int t;
    cin >> t;
    long long noOfDivsors = 1;
    long long productOfDivisors = 1;
    long long sumOfDivisors = 1;
    long long mod = 1000000007;
    long long val;
    long long exp = 1;

    while(t-- > 0){
        long long prime;
        long long power;

        cin >> prime >> power;

        noOfDivsors = (noOfDivsors * (power + 1) )% mod;

        sumOfDivisors = (sumOfDivisors * ( ( (pow(prime,power + 1,mod) - 1) * inv(prime - 1LL,mod) ) % mod )) % mod ;

        val = pow(prime,((power * (power+1))/2)  % (mod-1),mod);
        productOfDivisors = (pow(productOfDivisors,power+1,mod) * pow(val,exp,mod)) % mod;

        exp = (exp* (power+1)) % (mod - 1);

    }
    cout << noOfDivsors << " " << sumOfDivisors << " " << productOfDivisors;

}