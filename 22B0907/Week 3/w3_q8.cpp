#include <iostream>
#include <vector>
#include <cstdint>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> inp(n, 0);
    for(int i = 0; i < n; i++) cin >> inp[i];

    vector<int> dupli(inp);
    sort(dupli.begin(), dupli.end());
    vector<long long> dp(n, INT64_MAX);

    long long min_ob = INT64_MAX;
    for(int i = 0; i < n; i++){
        min_ob = INT64_MAX;
        for(int j = 0; j < n; j++){
            if(i == 0){
                dp[j] = abs(inp[i] - dupli[j]);
            } else {
                min_ob = min(min_ob, dp[j]);
                dp[j] = min_ob + abs(inp[i] - dupli[j]);
            }
        }
    }

    cout << *min_element(dp.begin(), dp.end()) << endl;
    return 0;
}