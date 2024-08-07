#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string input;
    cin >> input;

    vector<char> charVec(input.begin(),input.end());
    int best = 1, sum = 1;
    for ( int i = 1; i < charVec.size(); i++){
        if ( charVec[i] == charVec[i-1] ) {
            sum = sum + 1;
        }
        else {
            best = max(best, sum); 
            sum = 1;
        }
    }

    cout << max(best, sum);
}