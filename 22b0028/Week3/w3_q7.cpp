#include<bits/stdc++.h>

using namespace std;

int main(){
    long totalLength;
    int n;
    cin  >> totalLength >> n;

    long* lengths = new long[n];

    for (int i = 0; i < n; i++){
        cin >> lengths[i];
    }

    priority_queue<long,vector<long>,greater<long>> pq(lengths,lengths+n);

    long cost = 0;
    long currCost = 0;

    while(pq.size() > 1){
        currCost = pq.top();
        pq.pop();
        currCost += pq.top();
        pq.pop();
        cost += currCost;
        pq.push(currCost);
        currCost = 0;
    }

    cout << cost;

}