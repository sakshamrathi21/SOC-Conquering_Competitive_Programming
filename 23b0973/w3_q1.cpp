#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
        long long int n;
        cin >> n;
        vector< long long int> dr(n);
        vector<long long int> dl(n);
        long long int s;
        s = 0;
        for(long long int i=0; i<n; i++){
                cin >> dr[i] >> dl[i];
                s += dl[i] - dr[i];
        }
        sort(dr.begin(),dr.end());
        for(long long int i=0; i<n-1;i++){
                s -= (dr[i])*(n-i-1);
        }
        cout << s <<endl;
}