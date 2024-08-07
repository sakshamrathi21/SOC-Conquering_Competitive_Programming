#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int n = s.length();
    int maxLength = 0;
    int counter = 0;

    stack<int> stack;
    vector<int> d(n, -1);
    vector<int> c(n, -1);

    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            stack.push(i);
        } else {
            if (stack.empty()) {
                d[i] = -1;
                c[i] = -1;
            } else {
                d[i] = stack.top();
                stack.pop();
                c[i] = d[i];
                if (d[i] > 0 && d[i] < c.size() && c[d[i] - 1] != -1 && s[d[i] - 1] == ')') {
                    c[i] = c[d[i] - 1];
                }
            }
        }
    }

    counter = 1;
    for (int i = 0; i < n; i++) {
        if (s[i] == ')') {
            if (c[i] != -1) {
                if (i - c[i] + 1 == maxLength && i != 0) {
                    counter++;
                }
                if (maxLength < i - c[i] + 1) {
                    maxLength = i - c[i] + 1;
                    counter = 1;
                }
            }
        }
    }

    cout << maxLength << " " << counter << endl;

    return 0;
}
