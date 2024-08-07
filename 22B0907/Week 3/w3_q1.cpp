#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main(){
    long long n;
    cin >> n;
    vector<int> durations(n, 0);
    vector<int> deadlines(n, 0);
    for(int i = 0; i < n; i++)
    cin >> durations[i] >> deadlines[i];

    sort(durations.begin(), durations.end());
    // long long sum = accumulate(deadlines.begin(), deadlines.end(), 0);
    long long sum = 0;
    for(int i = 0; i < n; i++) sum += deadlines[i];
    for(int i = 0; i < n; i++){
        sum -= (n-i) * durations[i];
    }

    cout << sum << endl;

    return 0;
}