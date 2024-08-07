#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int l, r;
        cin >> l >> r;
        long long int lucky_no = l;
        int max_diff = 0;
        while (l <= r)
        {
            int min_digit = 9;
            int max_digit = 0;
            long long int n = l;
            while (n > 0)
            {
                int digit = n % 10;
                if (digit > max_digit)
                {
                    max_digit = digit;
                }
                if (digit < min_digit)
                {
                    min_digit = digit;
                }
                n = n / 10;
            }
            int diff = max_digit - min_digit;
            if (diff > max_diff)
            {
                max_diff = diff;
                lucky_no = l;
            }
            if (max_diff==9)
            {
                break;
            }
            l++;
        }
        cout << lucky_no << "\n";
    }
}