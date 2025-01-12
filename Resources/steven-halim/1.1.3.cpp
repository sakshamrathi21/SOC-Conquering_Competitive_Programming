#include<iostream>
#include<cmath>
using namespace std;
typedef long long ll;
typedef long double db;
typedef vector<ll> vll;
typedef vector<db> vdb;

int nextUnmatchedIndex(int n, bool* matched) {
    for (int i = 0 ; i < n ; i ++) {
        if (!matched[i]) return i;
    }
    return -1;
}

db distance_g(pair<db, db> p1, pair<db, db> p2) {
    return sqrt(pow((p1.first-p2.first), 2) + pow((p1.second-p2.second), 2));
}

db fun(vector<pair<db, db>> &points, int index, bool* matched, db currentCost, db minCost) {
    // cout << " hello " << points.size() << endl;
    if (currentCost >= minCost) return currentCost;
    if (index >= points.size()) return currentCost;
    // cout << " hello1 " << points.size() << endl;
    matched[index] = true;
    for (int i = index + 1 ; i < points.size(); i++) {
        matched[i] = true;
        db distance = distance_g(points[i], points[index]);
        currentCost += distance;
        int j = nextUnmatchedIndex(points.size(), matched);
        if (j == -1) {
            minCost = min(minCost, currentCost);
            matched[i] = false;
            break;
        }
        else {
            db newcost = fun(points, j, matched, currentCost, minCost);
            minCost = min(minCost, newcost);
        }
        matched[i] = false;
        currentCost -= distance;
    }
    matched[index] = false;
    return minCost;
}

int main() {
    vector<pair<db, db>> points;
    int n;
    cin >> n;
    bool matched[n];
    for (int i = 0 ; i < n ; i ++ ) { 
        db x, y;
        cin >> x >> y;
        points.push_back(make_pair(x, y));
        matched[i] = false;
    }
    // cout << "check " << points.size() << endl;
    cout << fun(points, 0, matched, 0, 100000);
}