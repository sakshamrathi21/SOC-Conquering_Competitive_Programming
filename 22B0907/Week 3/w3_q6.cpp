#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n, w;
    cin >> n >> w;
    vector<int> values(n);
    vector<int> weights(n);
    long long sumval = 0;
    for(int i = 0; i < n; i++){
        cin >> weights[i] >> values[i];
        sumval += values[i];
    }

    vector<long long> dp(sumval+1, 1e12 + 10);
    dp[0] = 0;
    for(int i = 0; i < n; i++){
        for(int j = sumval; j >= 0; j--){
            if(j >= values[i]){
                dp[j] = min(dp[j], dp[j-values[i]] + weights[i]);
            }
        }
    }

    for(int i = sumval; i >= 0; i--){
        if(dp[i] <= w){
            cout << i << endl;
            break;
        }
    }

    return 0;
}