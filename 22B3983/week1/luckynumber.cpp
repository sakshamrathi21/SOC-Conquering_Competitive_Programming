#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

int main()
{

    ll t;
    cin >> t;

    ll l, r;
    cin >> l;
    cin >> r;
    ll currentluckiest_number = -1;
    int max_luckieness = -1;
    for (ll i = l; i <= r; ++i)
    {
        ll current_number = i;
        ll largest_digit = current_number % 10;
        ll smallest_digit = largest_digit;

        while (current_number > 0)
            {
                ll int current_digit = current_number % 10;
                largest_digit = max(current_digit, largest_digit);
                smallest_digit = min(current_digit, smallest_digit);
            }
        int luckiness = largest_digit - smallest_digit;
        if (luckiness > max_luckieness)
            {
                currentluckiest_number = i;
                max_luckieness = luckiness;
            }
    }
    if (max_luckieness == -1)
        cout << "no lucky number found" << endl;
    else
        cout << currentluckiest_number << endl;
    return 0;
}