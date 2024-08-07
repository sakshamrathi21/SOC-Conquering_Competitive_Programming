#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<long long> dp(n, 0);
    int num = pow(10, 9) + 7;
    for(int i = 0; (i < 6 && i < n); i++) dp[i] = 1;
    for(int i = 1; i < n; i++){
        for(int j = 0; (j < i && j < 6); j++){
            dp[i] += dp[i-j-1];
        }
        dp[i] = (dp[i])%num;
    }

    cout << dp[n-1] << endl;

    return 0;
}