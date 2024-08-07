#include <iostream>
using namespace std;
#define ll long long
int main()
{

    ll t;
    cin >> t;


    while (t > 0)
    {
        ll n, k;
        cin >> n >> k;
        if ((n % 2 == 1) && (k != 2))
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
}