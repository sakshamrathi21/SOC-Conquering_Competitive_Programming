#include<bits/stdc++.h>

using namespace std;

long long inv(long long a,long long mod){
    return a <= 1 ? a : mod - (((mod/a) * inv(mod % a,mod)) % mod);
}
int main(){


    long long n;
    cin >> n;

    long long mod = 1000000007LL;
    long long result = 0;
    for(long long i = 1; i*i <= n; i++){
        long long t1 = i * (n/i - i + 1);

        long long t2 = (((n/i % mod) *( (n/i + 1) % mod ) % mod)* inv(2LL,mod)) % mod;

        long long t3 = ((i * (i+1)) / 2LL) % mod;

        long long t4 = t2 - t3 > 0 ? t2 - t3 : (mod + t2 - t3) % mod;

        result = (result + t4 + t1) % mod;

    }
    cout << result;

}