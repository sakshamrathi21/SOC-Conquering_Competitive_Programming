#include <iostream>
#include <vector>
using namespace std;

#define MOD 1000000007

int mypow(int x, int y, int mod){
    int ret;
    long long temp = 1;
    if(y == 0) return 1;
    if(y == 1) return x;
    temp = mypow(x, y/2, mod);
    if(y % 2 == 0){
        temp = temp * temp;
        ret = temp % mod;
    } else {
        temp = temp * temp;
        temp = temp % mod;
        temp = temp * x;
        ret = temp % mod;
    }
    return ret;
}

long long allsum(long long a, long long b, long long & two_inv){
    // long long sum1 = (a * ((a-1+MOD)%MOD)) % MOD;
    // sum1 = (sum1 * two_inv) % MOD;
    // long long sum2 = (b * ((b+1)%MOD)) % MOD;
    // sum2 = (sum2 * two_inv) % MOD;
    // return (sum2-sum1+MOD)%MOD;

    long long sum1 = (b-a+1)%MOD;
    long long sum2 = (b+a)%MOD;
    sum1 = (sum1 * sum2)%MOD;
    sum1 = (sum1 * two_inv)%MOD;
    return sum1;
}

int main(){
    long long N;
    cin >> N;
    long long final_result = 0;

    long long two_inv = mypow(2, MOD-2, MOD);

    // // O(n) approach
    // for(long long i = 1; i <= N; i++){
    //     final_result += (N - (N % i));
    //     final_result = final_result % num;
    // }

    // O(sqrt(n)) approach
    // q = floor(n/d) where d is divisor
    long long d = 1, q, last_d;
    while(d <= N){
        q = N/d;
        last_d = N/q;
        final_result += (allsum(d, last_d, two_inv) * q) % MOD;
        final_result %= MOD;
        d = last_d+1;
    }

    cout << (final_result) << endl;

    return 0;
}