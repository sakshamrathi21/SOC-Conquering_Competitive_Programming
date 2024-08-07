#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    int n;
    cin >> n;
    vector<int> len(n, 0);
    for(int i = 0; i < n; i++) cin >> len[i];
    sort(len.begin(), len.end());
    long long result = 0;
    if(n%2 == 0){
        int med1 = len[(n/2) - 1];
        int med2 = len[(n/2)];
        long long temp1 = 0, temp2 = 0;
        for(int i = 0; i < n; i++){
            temp1 += abs(len[i] - med1);
            temp2 += abs(len[i] - med2);
        }
        result = min(temp1, temp2);
    } else {
        int med = len[(n-1)/2];
        for(int i = 0; i < n; i++){
            result += abs(len[i] - med);
        }
    }

    cout << result << endl;

    return 0;

}