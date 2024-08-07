#include<bits/stdc++.h>
using namespace std;
int find (int n,vector<long long int>&dp){
        if(n==1||n==0) return 1;
        if (n<0) return 0;
        if(dp[n]!=-1) return dp[n];

        dp[n]=0;
        for(int i=1;i<7;i++){
                dp[n]=dp[n]+find(n-i,dp);}
        dp[n]%=1000000007;

        return dp[n];
}
int main(){
        int n;cin>>n;
        vector<long long int> dp(n+1,-1);
        cout<<find(n,dp);

}


