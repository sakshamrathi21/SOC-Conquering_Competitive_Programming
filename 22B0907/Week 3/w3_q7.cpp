#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int x, n;
    cin >> x >> n;
    vector<int> lengths(n, 0);
    for(int i = 0; i < n; i++) cin >> lengths[i];

    priority_queue<int, vector<int>, greater<int> > pq;
    for(int i = 0; i < n; i++) pq.push(lengths[i]);
    int temp1, temp2;
    long long result = 0;
    for(int i = 0; i < n-1; i++){
        temp1 = pq.top();
        pq.pop();
        temp2 = pq.top();
        pq.pop();
        result += (temp1 + temp2);
        pq.push(temp1 + temp2);
    }

    cout << result << endl;

    return 0;
}