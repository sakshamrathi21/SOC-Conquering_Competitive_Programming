#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

bool report;
int nodes;

void hasCycle(vector<set<int>>& graph, vector<bool>& vis, int curr, int par, int node) {
    nodes = max(node, nodes);
    vis[curr] = true;

    for (int j : graph[curr]) {
        if (vis[j] && j != par) {
            report = true;
        } else if (!vis[j]) {
            hasCycle(graph, vis, j, curr, node + 1);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    stringstream s;
    while (t-- > 0) {
        int n;
        cin >> n;
        vector<int> nums(n);
        vector<bool> vis(n, false);
        int counter1 = 0, counter2 = 0, counter3 = 0;

        vector<set<int>> graph(n);
        for (int i = 0; i < n; ++i) {
            cin >> nums[i];
            nums[i]--;
            graph[nums[i]].insert(i);
            graph[i].insert(nums[i]);
        }

        for (int i = 0; i < graph.size(); ++i) {
            if (!vis[i]) {
                report = false;
                nodes = 1;
                hasCycle(graph, vis, i, -1, nodes);
                if (report) {
                    if (nodes == 2) {
                        counter2++;
                    } else {
                        counter1++;
                    }
                } else {
                    counter3++;
                }
            }
        }

        int max = counter1 + counter2 + counter3;
        int min = counter1;
        if (counter2 != 0 || counter3 != 0) {
            min += 1;
        }
        s << min << " " << max << "\n";
    }
    cout << s.str();

    return 0;
}
