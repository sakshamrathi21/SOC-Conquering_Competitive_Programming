#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    int n1 = s1.size();
    int n2 = s2.size();
    
    vector<vector<int> > dp(n1+1, vector<int>(n2+1, 0));
    for(int i = 0; i <= n1; i++) dp[i][0] = i;
    for(int j = 0; j <= n2; j++) dp[0][j] = j;

    int temp1 = INT16_MAX;
    int temp2 = INT16_MAX;
    int temp3 = INT16_MAX;
    int val = INT16_MAX;
    for(int j = 1; j <= n2; j++){
        for(int i = 1; i <= n1; i++){
            temp1 = dp[i-1][j] + 1;
            temp2 = dp[i][j-1] + 1;
            temp3 = dp[i-1][j-1];
            if(s1[i-1] != s2[j-1]) temp3 += 1;
            val = min(temp1, temp2);
            val = min(val, temp3);
            if(val != INT16_MAX){
                dp[i][j] = val;
            }
        }
    }

    cout << dp[n1][n2] << endl;

    return 0;
}