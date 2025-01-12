/**
 *    Author: Saksham Rathi
 *    Created: Sat Nov 30 13:05:10 IST 2024
**/


#include<iostream>
#include<cmath>
#include<ctime>
#include <iomanip>
#include<numbers>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<unordered_map>
#include<unordered_set>
using namespace std;
typedef long long ll;
typedef long double db;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<db> vdb;
#define MOD 1000000000


int main() {
    int K;
    cin >> K;
    for (int t = 0 ; t < K ; t ++ ) {
        int N;
        cin >> N;
        vector<int> A(10010, 0);
        vector<vector<int>> B(N);
        for (int i = 0 ; i < N ; i ++) {
            int M;
            cin >> M;
            for (int j = 0 ; j < M ; j ++ ) {
                int x;
                cin >> x;
                A[x] ++;
                B[i].push_back(x);
            }  
        }
        vector<int> cnt(N, 0);
        int total_cnt = 0;
        for (int i = 0 ; i < N ; i ++) {
            for (int j = 0 ; j < B[i].size() ; j ++ ) {
                if (A[B[i][j]] == 1) {
                    cnt[i] ++;
                    total_cnt ++;
                }
            }
        }
        cout << "Case " << t + 1 << ":";
        for (int i = 0 ; i < N ; i ++ ) {
            cout << " " << fixed << setprecision(6) << (double)cnt[i] / total_cnt * 100 << "%";
        }
    }
}
