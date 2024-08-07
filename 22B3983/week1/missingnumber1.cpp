#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;

    int xor_sum = 0;

    for (int i = 1; i <= n; ++i)
    {
        xor_sum ^= i;
    }

    for (int i = 0; i < n - 1; ++i)
    {
        int number;
        cin >> number;
        xor_sum ^= number;
    }

    cout << xor_sum << endl;

    return 0;
}
