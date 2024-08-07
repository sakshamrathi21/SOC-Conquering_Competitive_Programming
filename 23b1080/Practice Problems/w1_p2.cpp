#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void move(int n, int a, int b) {
    int c = 6 - a - b;
    if (n == 1) {
        cout << a << " " << b << "\n";
        return;
    }
    move(n-1, a, c);
    cout << a << " " << b << "\n";
    move(n-1, c, b);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // Time complexity would be O(2^n)
    int n;
    cin >> n;
    cout << (1<<n)-1 << "\n";
    move(n, 1, 3);
}