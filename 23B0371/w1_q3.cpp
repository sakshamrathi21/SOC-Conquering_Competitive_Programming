#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
       int n, k;
        cin >> n >> k;

        if (k == 1) {
            cout << "YES\n";
        } else {
            if (n % 2 == 0) {
                cout << "YES\n";
            } else {
                int x = (n - k) / 2;
                if ((n - k) % 2 == 0) {
                    cout << "YES\n";
                } else {
                    cout << "NO\n";
                }
            }
        }
    }

    return 0;
}
