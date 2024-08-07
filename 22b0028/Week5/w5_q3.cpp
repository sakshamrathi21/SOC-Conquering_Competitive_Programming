#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    string result;

    while (t-- > 0) {
        long long num;
        cin >> num;
        bool large = true;
        long long lastDigit;

        while (num / 10 > 0) {
            lastDigit = 10 + (num % 10);
            if (lastDigit > 18) {
                large = false;
                break;
            }
            num /= 10;
            num--;
        }
        if (num != 0) {
            large = false;
        }

        if (large) result += "YES\n";
        else result += "NO\n";
    }

    cout << result;

    return 0;
}
